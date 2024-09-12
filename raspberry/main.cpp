#include "widget.h"
#include "loginwidget.h"
#include "userwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 创建登录窗口
    LoginWidget login;
    // 创建主窗口
    UserWindow userWindow;
    Widget w;
    //当登录成功时，显示主窗口并隐藏登录窗口
    QObject::connect(&login, &LoginWidget::loginSuccessful, [&](){
        login.hide();
        userWindow.setUserName(loggedInUser);  // 设置用户名
        userWindow.show();
        w.initializeUI();
    });
    w.show();
    login.show();
    return a.exec();
}

