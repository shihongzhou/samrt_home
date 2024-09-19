#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QTimer>
#include <QDateTime>
namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = nullptr);
    ~UserWidget();
    void InitUI();
private:

    void createCentralArea();
    Ui::UserWidget *ui;
    QTimer *timer;

private slots:
    void updateDateTime(); // 更新时间日期显示
    void on_mesgButton_clicked(); // 消息按钮点击事件
    void on_userButton_clicked(); // 用户按钮点击事件
};

#endif // USERWIDGET_H
