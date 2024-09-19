/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *TopStateBar;
    QHBoxLayout *horizontalLayout;
    QLabel *logoLabel;
    QLabel *networkLabel;
    QPushButton *mesgButton;
    QPushButton *userButton;
    QLabel *timeLabel;
    QComboBox *comboBox;

    void setupUi(QWidget *UserWidget)
    {
        if (UserWidget->objectName().isEmpty())
            UserWidget->setObjectName("UserWidget");
        UserWidget->resize(1024, 600);
        UserWidget->setMinimumSize(QSize(10, 10));
        UserWidget->setBaseSize(QSize(0, 0));
        widget = new QWidget(UserWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 451, 34));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TopStateBar = new QWidget(widget);
        TopStateBar->setObjectName("TopStateBar");
        TopStateBar->setMinimumSize(QSize(0, 32));
        TopStateBar->setMaximumSize(QSize(16777215, 32));
        horizontalLayout = new QHBoxLayout(TopStateBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        logoLabel = new QLabel(TopStateBar);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(32, 32));
        logoLabel->setMaximumSize(QSize(32, 32));
        logoLabel->setStyleSheet(QString::fromUtf8(""));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resources/logo.png")));

        horizontalLayout->addWidget(logoLabel);

        networkLabel = new QLabel(TopStateBar);
        networkLabel->setObjectName("networkLabel");
        networkLabel->setMinimumSize(QSize(32, 32));
        networkLabel->setMaximumSize(QSize(32, 32));
        networkLabel->setStyleSheet(QString::fromUtf8(""));
        networkLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/resources/network_online.png")));

        horizontalLayout->addWidget(networkLabel);

        mesgButton = new QPushButton(TopStateBar);
        mesgButton->setObjectName("mesgButton");
        mesgButton->setMinimumSize(QSize(64, 32));
        mesgButton->setMaximumSize(QSize(64, 32));
        mesgButton->setBaseSize(QSize(10, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resources/message_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mesgButton->setIcon(icon);
        mesgButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(mesgButton);

        userButton = new QPushButton(TopStateBar);
        userButton->setObjectName("userButton");
        userButton->setMinimumSize(QSize(64, 32));
        userButton->setMaximumSize(QSize(64, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resources/user_avatar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        userButton->setIcon(icon1);
        userButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(userButton);


        horizontalLayout_2->addWidget(TopStateBar);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setMinimumSize(QSize(0, 32));
        timeLabel->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_2->addWidget(timeLabel);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(0, 32));
        comboBox->setMaximumSize(QSize(16777215, 32));

        horizontalLayout_2->addWidget(comboBox);


        retranslateUi(UserWidget);

        QMetaObject::connectSlotsByName(UserWidget);
    } // setupUi

    void retranslateUi(QWidget *UserWidget)
    {
        UserWidget->setWindowTitle(QCoreApplication::translate("UserWidget", "Smart Home Control Center", nullptr));
        logoLabel->setText(QString());
        networkLabel->setText(QString());
        mesgButton->setText(QCoreApplication::translate("UserWidget", "\346\266\210\346\201\257", nullptr));
        userButton->setText(QCoreApplication::translate("UserWidget", "\347\224\250\346\210\267", nullptr));
        timeLabel->setText(QCoreApplication::translate("UserWidget", "time", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("UserWidget", "\350\256\276\345\244\207\346\216\247\345\210\266", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("UserWidget", "\347\216\257\345\242\203\347\233\221\346\265\213", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("UserWidget", "\345\234\272\346\231\257\346\250\241\345\274\217", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("UserWidget", "\345\256\211\345\205\250\347\233\221\346\216\247", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("UserWidget", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));

    } // retranslateUi

};

namespace Ui {
    class UserWidget: public Ui_UserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
