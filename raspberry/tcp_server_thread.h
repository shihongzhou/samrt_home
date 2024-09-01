#ifndef TCP_SERVER_THREAD_H
#define TCP_SERVER_THREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>

// 自定义线程类，继承 QThread
class WorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit WorkerThread(QObject *parent = nullptr);
    ~WorkerThread();

protected:
    void run() override;

signals:
    void resultReady();
    void clientConnected(const QString &clientInfo);
    void dataReceived(const QString &data);
    void clientDisconnected();

private slots:
    void handleNewConnection();
    void handleClientDisconnected();
    void tcp_recv_data();

private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QByteArray buffer;
};

class tcp_server_thread : public QWidget
{
    Q_OBJECT

public:
    explicit tcp_server_thread(QWidget *parent = nullptr);
    ~tcp_server_thread();

private slots:
    void handleResults();
    void handleClientConnected(const QString &clientInfo);
    void handleDataReceived(const QString &data);
    void handleClientDisconnected();

private:
    WorkerThread *workerThread;
};

#endif // TCP_SERVER_THREAD_H
