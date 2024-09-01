#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /* 设置窗口属性 */
    setWindowTitle("Raspberry Stream Viewer");
    setFixedSize(1024, 600);

    // MJPEG Stream URL
    networkManager = new QNetworkAccessManager(this);

    // 初始化帧率显示标签
    frameRateLabel = new QLabel(this);
    frameRateLabel->setGeometry(10, 10, 100, 30); // 设置标签位置和大小
    frameRateLabel->setStyleSheet("color: green;\
                                  font-size: 16px;     \
                                  font-weight: bold;   \
                                  font-style: italic; ");

    // 初始化帧率计时器
    fpsTimer = new QTimer(this);
    connect(fpsTimer, &QTimer::timeout, this, &Widget::updateFrameRate);
    fpsTimer->start(1000); // 每秒更新一次帧率

    tcp_thread = new tcp_server_thread(NULL);
    /* connect http server endian*/
    connect_http_server();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connect_http_server()
{
    QUrl url("http://192.168.31.234:8080/?action=stream");

    // Start the MJPEG stream
    streamReply = networkManager->get(QNetworkRequest(url));
    connect(streamReply, &QNetworkReply::readyRead, this, &Widget::readStream);
    connect(streamReply, &QNetworkReply::finished, this, [&]() {
        QNetworkReply::NetworkError error = streamReply->error();
        if (error == QNetworkReply::NoError) {
            // 请求成功，处理收到的数据
            QByteArray data = streamReply->readAll();
            qDebug() << "Data received:" << data;
        } else {
            // 处理错误
            qDebug() << "Error occurred:" << error;
            qDebug() << "Error string:" << streamReply->errorString();

            if (error == QNetworkReply::RemoteHostClosedError) {
                qDebug() << "The connection was closed by the remote host.";
            } else if (error == QNetworkReply::ConnectionRefusedError) {
                qDebug() << "The connection was refused by the server.";
            } else if (error == QNetworkReply::TimeoutError) {
                qDebug() << "The connection timed out.";
            }
            // 可以根据需要添加更多的错误处理
        }
        streamReply->deleteLater();
    });
}

void Widget::readStream()
{
    //qDebug() << "recv a frame data";
    // 读取所有可用的数据并追加到缓冲区
    buffer.append(streamReply->readAll());

    // 查找JPEG图像的起始和结束标记
    int start = buffer.indexOf("\xff\xd8");  // JPEG 开始标志
    int end = buffer.indexOf("\xff\xd9");    // JPEG 结束标志

    if (start != -1 && end != -1 && end > start) {
        // 提取JPEG图像数据
        QByteArray imageData = buffer.mid(start, end - start + 2);

        // 清理已处理的数据
        buffer.remove(0, end + 2);

        QPixmap pixmap;
        if (pixmap.loadFromData(imageData)) {
            ui->video_label->setPixmap(pixmap.scaled(ui->video_label->size(), Qt::KeepAspectRatio));

            // 增加帧计数器
            frameCount++;

        } else {
            qDebug() << "Failed to load pixmap from data";
        }
    }
}

void Widget::updateFrameRate()
{
    /* error frame rate*/
    if(frameCount > 100) {
        frameCount = 0;
        return;
    }
    // 显示帧率
    frameRateLabel->setText(QString("FPS: %1").arg(frameCount));

    // 重置帧计数器
    frameCount = 0;
}

void Widget::handlerError(QNetworkReply::NetworkError error)
{
    qDebug() << "Network error:" << error;
    if (streamReply) {
        streamReply->abort();
    }
}

void Widget::on_pushButton_clicked()
{
    qDebug() << "repeat fresh video display!";
    connect_http_server();
}
