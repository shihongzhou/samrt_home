#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>


class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);

signals:
    void loginSuccessful(); // 登录成功的信号

private slots:
    void handleLogin(); // 登录按钮点击处理函数

private:

    QLineEdit *usernameInput; //存储用户输入的用户名
    QLineEdit *passwordInput; //存储用户输入的密码
    QLabel *statusLabel;    // 登录显示结果
    QPushButton *loginButton; //登录按钮，点击触发登录验证

};

#endif // LOGINWIDGET_H
