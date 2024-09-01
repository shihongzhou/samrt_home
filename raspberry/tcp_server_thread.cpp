#include "tcp_server_thread.h"
#include <QHostAddress>

// WorkerThread 构造函数
WorkerThread::WorkerThread(QObject *parent)
    : QThread(parent), tcpServer(nullptr), tcpSocket(nullptr)
{
}

WorkerThread::~WorkerThread()
{
    // 确保线程退出时清理资源
    if (tcpSocket) {
        tcpSocket->disconnectFromHost();
        tcpSocket->deleteLater();
    }
    if (tcpServer) {
        tcpServer->close();
        tcpServer->deleteLater();
    }
}

void WorkerThread::run()
{
    tcpServer = new QTcpServer();

    // 开始监听
    if (!tcpServer->listen(QHostAddress::Any, 8888)) {
        qDebug() << "Server could not start!";
        return;
    }
    qDebug() << "Server started, listening on port 8888";

    connect(tcpServer, &QTcpServer::newConnection, this, &WorkerThread::handleNewConnection);

    // 运行事件循环
    exec();
}

void WorkerThread::handleNewConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();

    QString clientInfo = QString("Client connected: [%1:%2]")
                             .arg(tcpSocket->peerAddress().toString())
                             .arg(tcpSocket->peerPort());

    emit clientConnected(clientInfo);

    connect(tcpSocket, &QTcpSocket::readyRead, this, &WorkerThread::tcp_recv_data);
    connect(tcpSocket, &QTcpSocket::disconnected, this, &WorkerThread::handleClientDisconnected);
}

void WorkerThread::tcp_recv_data()
{
    // 处理接收的数据并解析
    buffer.append(tcpSocket->readAll()); // 使用缓冲区处理粘包问题
    qDebug() << buffer;

    while (true) {
        // 查找每个消息的开始和结束标记
        int startIdx = buffer.indexOf("start:");
        int endIdx = buffer.indexOf(":end", startIdx);

        // 如果没有找到完整的一对标记，跳出循环，等待更多数据
        if (startIdx == -1 || endIdx == -1) {
            break;
        }

        // 计算消息长度
        int messageLength = endIdx + 4 - startIdx; // 4 是 ":end" 的长度

        // 提取完整消息
        QByteArray messageData = buffer.mid(startIdx, messageLength);
        buffer.remove(0, startIdx + messageLength); // 从缓冲区中移除已处理的数据

        // 将数据转换为QString并解析
        QString data = QString(messageData);

        // 检查数据是否以 "start:" 开头和以 ":end" 结尾
        if (data.startsWith("start:") && data.endsWith(":end")) {
            // 去掉 "start:" 和 ":end"
            data = data.mid(6, data.length() - 10);

            // 解析 "name%value%name%value" 部分
            QStringList pairs = data.split("%");
            if (pairs.size() % 2 == 0) { // 需要有偶数个元素
                for (int i = 0; i < pairs.size(); i += 2) {
                    QString name = pairs[i];
                    QString value = pairs[i + 1];
                    qDebug() << "Parsed name:" << name;
                    qDebug() << "Parsed value:" << value;
                }
            } else {
                qDebug() << "Invalid data format. Expected pairs of 'name%value'.";
            }
        } else {
            qDebug() << "Invalid data format. Expected 'start:name%value%...%name%value:end'.";
        }
    }
}

void WorkerThread::handleClientDisconnected()
{
    emit clientDisconnected();
    if (tcpSocket) {
        tcpSocket->deleteLater();
        tcpSocket = nullptr;
    }
}

// tcp_server_thread 构造函数
tcp_server_thread::tcp_server_thread(QWidget *parent)
    : QWidget(parent)
{
    workerThread = new WorkerThread(this);

    // 连接 WorkerThread 的信号到相应的槽
    connect(workerThread, &WorkerThread::resultReady, this, &tcp_server_thread::handleResults);
    connect(workerThread, &WorkerThread::clientConnected, this, &tcp_server_thread::handleClientConnected);
    connect(workerThread, &WorkerThread::dataReceived, this, &tcp_server_thread::handleDataReceived);
    connect(workerThread, &WorkerThread::clientDisconnected, this, &tcp_server_thread::handleClientDisconnected);
    connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);

    workerThread->start();  // 启动线程
}

tcp_server_thread::~tcp_server_thread()
{
    workerThread->quit();  // 请求线程结束
    workerThread->wait();  // 等待线程结束
}

void tcp_server_thread::handleResults()
{
    qDebug() << "Thread finished execution.";
}

void tcp_server_thread::handleClientConnected(const QString &clientInfo)
{
    qDebug() << clientInfo;
}

void tcp_server_thread::handleDataReceived(const QString &data)
{
    qDebug() << "Data received from client:" << data;
}

void tcp_server_thread::handleClientDisconnected()
{
    qDebug() << "Client disconnected.";
}
