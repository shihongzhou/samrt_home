#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("登录界面");
    setFixedSize(300,150);

    //创建用户名和密码输入框
    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Username");
    usernameInput->setGeometry(50,20,200,30);

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("password");
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordInput->setGeometry(50, 60, 200, 30);

    //设置登录按钮
    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(100,100, 100,30);
    //按钮与槽函数连接
    connect(loginButton, &QPushButton::clicked, this, &LoginWidget::handleLogin);

    //状态标签，显示登录成功或失败
    statusLabel = new QLabel(this);
    statusLabel->setGeometry(50,80,200,20);
}

void LoginWidget::handleLogin()
{
    // 简单验证逻辑，可以根据需要替换为网络请求或数据库验证
    if (usernameInput->text() == "1" && passwordInput->text() == "1") {
        emit loginSuccessful();  // 触发登录成功信号
    } else {
        statusLabel->setText("Invalid login. Try again.");
    }
}
