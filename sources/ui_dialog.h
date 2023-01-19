/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QCustomPlot *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *but_zoom_in;
    QPushButton *but_zoom_out;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_zoom;
    QPushButton *but_build_graf;
    QLineEdit *line_text_graf;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_accursy;
    QCheckBox *checkBox_point;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(500, 410);
        Dialog->setMinimumSize(QSize(500, 410));
        Dialog->setMaximumSize(QSize(500, 440));
        Dialog->setStyleSheet(QString::fromUtf8(""));
        widget = new QCustomPlot(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 481, 281));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 136, 136);"));
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 370, 481, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        but_zoom_in = new QPushButton(horizontalLayoutWidget);
        but_zoom_in->setObjectName(QString::fromUtf8("but_zoom_in"));
        but_zoom_in->setMinimumSize(QSize(85, 30));
        but_zoom_in->setMaximumSize(QSize(105, 30));
        but_zoom_in->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(92, 92, 92);"));
        but_zoom_in->setIconSize(QSize(33, 33));

        horizontalLayout->addWidget(but_zoom_in);

        but_zoom_out = new QPushButton(horizontalLayoutWidget);
        but_zoom_out->setObjectName(QString::fromUtf8("but_zoom_out"));
        but_zoom_out->setMinimumSize(QSize(85, 30));
        but_zoom_out->setMaximumSize(QSize(105, 30));
        but_zoom_out->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(92, 92, 92);"));
        but_zoom_out->setIconSize(QSize(33, 33));

        horizontalLayout->addWidget(but_zoom_out, 0, Qt::AlignHCenter);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_zoom = new QLabel(horizontalLayoutWidget);
        label_zoom->setObjectName(QString::fromUtf8("label_zoom"));
        label_zoom->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_zoom);


        horizontalLayout->addLayout(verticalLayout);

        but_build_graf = new QPushButton(horizontalLayoutWidget);
        but_build_graf->setObjectName(QString::fromUtf8("but_build_graf"));
        but_build_graf->setMinimumSize(QSize(85, 25));
        but_build_graf->setMaximumSize(QSize(105, 30));
        but_build_graf->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(92, 92, 92);"));

        horizontalLayout->addWidget(but_build_graf);

        line_text_graf = new QLineEdit(Dialog);
        line_text_graf->setObjectName(QString::fromUtf8("line_text_graf"));
        line_text_graf->setGeometry(QRect(10, 10, 481, 41));
        horizontalLayoutWidget_2 = new QWidget(Dialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 340, 481, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_accursy = new QCheckBox(horizontalLayoutWidget_2);
        checkBox_accursy->setObjectName(QString::fromUtf8("checkBox_accursy"));

        horizontalLayout_2->addWidget(checkBox_accursy);

        checkBox_point = new QCheckBox(horizontalLayoutWidget_2);
        checkBox_point->setObjectName(QString::fromUtf8("checkBox_point"));

        horizontalLayout_2->addWidget(checkBox_point);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        but_zoom_in->setText(QCoreApplication::translate("Dialog", "Zoom_in", nullptr));
        but_zoom_out->setText(QCoreApplication::translate("Dialog", "Zoom_out", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Zoom:", nullptr));
        label_zoom->setText(QCoreApplication::translate("Dialog", "1x", nullptr));
        but_build_graf->setText(QCoreApplication::translate("Dialog", "Build", nullptr));
        checkBox_accursy->setText(QCoreApplication::translate("Dialog", "\320\221\320\276\320\273\320\265\320\265 \321\202\320\276\321\207\320\275\320\276\320\265 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265", nullptr));
        checkBox_point->setText(QCoreApplication::translate("Dialog", "\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\260 \321\202\320\276\321\207\320\272\320\260\320\274\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
