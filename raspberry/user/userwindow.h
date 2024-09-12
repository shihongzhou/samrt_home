#ifndef USERWINDOW_H
#define USERWINDOW_H

#include "loginwidget.h"
#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>

namespace Ui {
    class UserWindow;  // 声明UI类
}

class UserWindow : public QWidget
{
    Q_OBJECT
public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();
    void setUserName(const QString &userName);  // 设置用户名的方法
private:
    // 顶部导航栏
    Ui::UserWindow *ui;  // UI类的指针
    QLabel *appNameLabel;
    QLabel *userInfoLabel;

    // 设备列表区域
    QListWidget *deviceListWidget;

    // 设备控制面板
    QStackedWidget *deviceControlPanel;

    // 底部工具栏
    QPushButton *sceneSwitchButton;
    QPushButton *settingsButton;

    // 界面布局
    QVBoxLayout *mainLayout;
    QHBoxLayout *topNavBar;
    QHBoxLayout *bottomToolBar;

    void setupUI();  // 初始化UI
    void setupTopNavBar();  // 初始化顶部导航栏
    void setupDeviceList();  // 初始化设备列表
    void setupDeviceControlPanel();  // 初始化设备控制面板
    void setupBottomToolBar();  // 初始化底部工具栏


signals:
};

#endif // USERWINDOW_H
