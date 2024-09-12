#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkReply>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include "tcp_server_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QNetworkAccessManager *networkManager;
    QNetworkReply *streamReply;
    QByteArray buffer;  // 用于存储接收到的数据
    QLabel *frameRateLabel;
    QTimer *fpsTimer;
    unsigned int frameCount;

    /* 自定义的类*/
    tcp_server_thread *tcp_thread;

    void connect_http_server(void);
    void updateFrameRate(void);
    void initializeUI(void);

private:
    Ui::Widget *ui;

private slots:
    /* 此槽函数用来接收数据流信息*/
    void readStream();
    void handlerError(QNetworkReply::NetworkError);
    void on_pushButton_clicked();
};
#endif // WIDGET_H
