#include "userwindow.h"
#include "userwidget.h"  // 包含自动生成的ui文件

UserWindow::UserWindow(QWidget *parent)
    : QWidge{parent},
    ui(new Ui::UserWindow)  // 初始化UI类
{
    ui->setupUi(this);  // 关联UI文件
    setupUI();
}

UserWindow::~UserWindow()
{
    delete ui;  // 清理UI类指针
}
void UserWindow::setupUI()
{
    // 创建主布局
    mainLayout = new QVBoxLayout(this);

    // 初始化各部分
    setupTopNavBar();
    setupDeviceList();
    setupDeviceControlPanel();
    setupBottomToolBar();

    // 将各部分添加到主布局中
    mainLayout->addLayout(topNavBar);  // 添加顶部导航栏
    mainLayout->addWidget(deviceListWidget);  // 添加设备列表
    mainLayout->addWidget(deviceControlPanel);  // 添加设备控制面板
    mainLayout->addLayout(bottomToolBar);  // 添加底部工具栏

    setLayout(mainLayout);  // 应用布局
}
void UserWindow::setupTopNavBar()
{
    // 创建顶部导航栏布局
    topNavBar = new QHBoxLayout();

    // 创建应用名称和用户信息
    appNameLabel = new QLabel("Smart Home Control Center");
    userInfoLabel = new QLabel("User: (Not Logged In)");

    // 设置字体和样式
    appNameLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    userInfoLabel->setStyleSheet("font-size: 14px;");

    // 将组件添加到导航栏
    topNavBar->addWidget(appNameLabel);
    topNavBar->addStretch();  // 将用户信息放在右边
    topNavBar->addWidget(userInfoLabel);
}

void UserWindow::setupDeviceList()
{
    // 创建设备列表
    deviceListWidget = new QListWidget();

    // 添加示例设备
    deviceListWidget->addItem("Living Room Light");
    deviceListWidget->addItem("Bedroom AC");
    deviceListWidget->addItem("Security Camera");

    // 设置选择模式
    deviceListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // 设置设备列表大小
    deviceListWidget->setFixedWidth(200);
}

void UserWindow::setupDeviceControlPanel()
{
    // 创建堆叠小部件，用于在设备控制面板之间切换
    deviceControlPanel = new QStackedWidget(this);

    // 创建示例设备控制界面
    QLabel *lightControl = new QLabel("Light Control Panel");
    QLabel *acControl = new QLabel("AC Control Panel");
    QLabel *cameraControl = new QLabel("Camera Control Panel");

    // 添加到堆叠小部件中
    deviceControlPanel->addWidget(lightControl);
    deviceControlPanel->addWidget(acControl);
    deviceControlPanel->addWidget(cameraControl);

    // 根据设备列表的选择切换设备控制面板
    connect(deviceListWidget, &QListWidget::currentRowChanged, deviceControlPanel, &QStackedWidget::setCurrentIndex);
}

void UserWindow::setupBottomToolBar()
{
    // 创建底部工具栏布局
    bottomToolBar = new QHBoxLayout();

    // 创建按钮
    sceneSwitchButton = new QPushButton("Scene Switch");
    settingsButton = new QPushButton("Settings");

    // 将按钮添加到工具栏
    bottomToolBar->addWidget(sceneSwitchButton);
    bottomToolBar->addStretch();
    bottomToolBar->addWidget(settingsButton);
}


void UserWindow::setUserName(const QString &userName)
{
    // 更新用户信息标签，显示登录的用户名
    userInfoLabel->setText("User: " + userName);
}
