/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *video_label;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1024, 600);
        video_label = new QLabel(Widget);
        video_label->setObjectName("video_label");
        video_label->setGeometry(QRect(0, 0, 800, 600));
        video_label->setMinimumSize(QSize(800, 600));
        video_label->setMaximumSize(QSize(800, 600));
        video_label->setContextMenuPolicy(Qt::DefaultContextMenu);
        video_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;                /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    background-color: lightgray; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    border: 3px solid black;     /* \350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    border-radius: 5px;          /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"}\n"
""));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(890, 10, 80, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 lightblue, stop: 1 blue); /* \344\273\216\344\270\212\345\210\260\344\270\213\347\232\204\347\272\277\346\200\247\346\270\220\345\217\230 */\n"
"    color: white;\n"
"    border: 2px solid black;\n"
"    border-radius: 5px;\n"
"}\n"
""));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        video_label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "\351\207\215\346\226\260\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
