#include "userwidget.h"
#include "ui_userwidget.h"
#include <QDateTime>
#include <QPixmap>
#include <QMenu>
#include <QMessageBox>
#include <QStackedWidget>
//#include <QNetworkConfigurationManager>
UserWidget::UserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWidget)
{
    ui->setupUi(this);
    InitUI();
}


void UserWidget::InitUI()
{
    // 初始化时间日期显示
    ui->timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    // 创建一个定时器，每秒更新一次时间
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UserWidget::updateDateTime);
    timer->start(1000);
    // 设置消息通知按钮
    ui->mesgButton->setToolTip("您有2条未读消息");

    // 设置用户账户按钮
    ui->userButton->setToolTip("用户账户");

    // 连接按钮的点击事件（如果未在Qt Designer中自动连接）
    connect(ui->mesgButton, &QPushButton::clicked, this, &UserWidget::on_mesgButton_clicked);
    connect(ui->userButton, &QPushButton::clicked, this, &UserWidget::on_userButton_clicked);

    // 动态更新网络状态（可选）
    // QNetworkConfigurationManager *networkManager = new QNetworkConfigurationManager(this);
    // connect(networkManager, &QNetworkConfigurationManager::onlineStateChanged, this, &UserWidget::updateNetworkStatus);
    // updateNetworkStatus(networkManager->isOnline());
    createCentralArea();
}

void UserWidget::createCentralArea()
{
    // 创建 QStackedWidget
    QStackedWidget *stackedWidget = new QStackedWidget(this);

    // 创建每个子界面
    QWidget *deviceControlPage = new QWidget();
    QLabel *deviceLabel = new QLabel("设备控制界面", deviceControlPage);
    QVBoxLayout *deviceLayout = new QVBoxLayout(deviceControlPage);
    deviceLayout->addWidget(deviceLabel);
    deviceControlPage->setFixedSize(700, 500);  // 设置子界面的大小

    // 环境监测界面
    QWidget *environmentMonitorPage = new QWidget();
    QLabel *envLabel = new QLabel("环境监测界面", environmentMonitorPage);
    QVBoxLayout *envLayout = new QVBoxLayout(environmentMonitorPage);
    envLayout->addWidget(envLabel);
    environmentMonitorPage->setFixedSize(700, 500);

    // 场景模式界面
    QWidget *sceneModePage = new QWidget();
    QLabel *sceneLabel = new QLabel("场景模式界面", sceneModePage);
    QVBoxLayout *sceneLayout = new QVBoxLayout(sceneModePage);
    sceneLayout->addWidget(sceneLabel);
    sceneModePage->setFixedSize(700, 500);

    // 安全监控界面
    QWidget *securityMonitorPage = new QWidget();
    QLabel *securityLabel = new QLabel("安全监控界面", securityMonitorPage);
    QVBoxLayout *securityLayout = new QVBoxLayout(securityMonitorPage);
    securityLayout->addWidget(securityLabel);
    securityMonitorPage->setFixedSize(700, 500);

    // 系统设置界面
    QWidget *systemSettingsPage = new QWidget();
    QLabel *systemLabel = new QLabel("系统设置界面", systemSettingsPage);
    QVBoxLayout *systemLayout = new QVBoxLayout(systemSettingsPage);
    systemLayout->addWidget(systemLabel);
    systemSettingsPage->setFixedSize(700, 500);

    // 将每个子界面添加到 QStackedWidget
    stackedWidget->addWidget(deviceControlPage);
    stackedWidget->addWidget(environmentMonitorPage);
    stackedWidget->addWidget(sceneModePage);
    stackedWidget->addWidget(securityMonitorPage);
    stackedWidget->addWidget(systemSettingsPage);
    systemLayout->addWidget(systemLabel);
    // 连接 ComboBox 的 currentIndexChanged 信号到 QStackedWidget 的 setCurrentIndex 槽
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            stackedWidget, &QStackedWidget::setCurrentIndex);

}

void UserWidget::updateDateTime()
{
    ui->timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    //qDebug() << "Current date and time: " << QDateTime::currentDateTime().toString();

}

void UserWidget::on_mesgButton_clicked()
{
    // 打开消息中心窗口的逻辑
    QMessageBox::information(this, "消息中心", "您有2条未读消息。");
}

void UserWidget::on_userButton_clicked()
{
    // 弹出用户菜单
    QMenu *menu = new QMenu(this);
    menu->addAction("个人信息", this, []() {
        // 打开个人信息窗口的逻辑
        qDebug() << "打开个人信息窗口";
    });
    menu->addAction("设置", this, []() {
        // 打开设置窗口的逻辑
        qDebug() << "打开设置窗口的逻辑";
    });
    menu->addAction("退出登录", this, []() {
        // 执行退出登录的逻辑
        qDebug() << "执行退出登录的逻辑";
    });

    // 在用户按钮下方显示菜单
    QPoint pos = ui->userButton->mapToGlobal(QPoint(0, ui->userButton->height()));
    menu->exec(pos);
}

// void UserWidget::updateNetworkStatus(bool isOnline)
// {
//     if (isOnline) {
//         QPixmap networkPixmap(":/resources/network_online.png");
//         ui->networkStatusLabel->setPixmap(networkPixmap.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//         ui->networkStatusLabel->setToolTip("网络连接正常");
//     } else {
//         QPixmap networkPixmap(":/resources/network_offline.png");
//         ui->networkStatusLabel->setPixmap(networkPixmap.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//         ui->networkStatusLabel->setToolTip("网络连接已断开");
//     }
// }


UserWidget::~UserWidget()
{
    delete ui;
}

