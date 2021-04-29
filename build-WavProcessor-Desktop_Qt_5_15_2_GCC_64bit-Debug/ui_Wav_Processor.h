/********************************************************************************
** Form generated from reading UI file 'Wav_Processor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAV_PROCESSOR_H
#define UI_WAV_PROCESSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wav_Processor
{
public:
    QWidget *centralwidget;
    QPushButton *FileButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *LoadButton;
    QPushButton *SaveButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Wav_Processor)
    {
        if (Wav_Processor->objectName().isEmpty())
            Wav_Processor->setObjectName(QString::fromUtf8("Wav_Processor"));
        Wav_Processor->resize(800, 600);
        centralwidget = new QWidget(Wav_Processor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FileButton = new QPushButton(centralwidget);
        FileButton->setObjectName(QString::fromUtf8("FileButton"));
        FileButton->setGeometry(QRect(10, 10, 89, 25));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 30, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LoadButton = new QPushButton(verticalLayoutWidget);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setEnabled(true);

        verticalLayout->addWidget(LoadButton);

        SaveButton = new QPushButton(verticalLayoutWidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        verticalLayout->addWidget(SaveButton);

        Wav_Processor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Wav_Processor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Wav_Processor->setMenuBar(menubar);
        statusbar = new QStatusBar(Wav_Processor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Wav_Processor->setStatusBar(statusbar);

        retranslateUi(Wav_Processor);

        QMetaObject::connectSlotsByName(Wav_Processor);
    } // setupUi

    void retranslateUi(QMainWindow *Wav_Processor)
    {
        Wav_Processor->setWindowTitle(QCoreApplication::translate("Wav_Processor", "Wav_Processor", nullptr));
        FileButton->setText(QCoreApplication::translate("Wav_Processor", "Files", nullptr));
        LoadButton->setText(QCoreApplication::translate("Wav_Processor", "Load File", nullptr));
        SaveButton->setText(QCoreApplication::translate("Wav_Processor", "Save File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wav_Processor: public Ui_Wav_Processor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAV_PROCESSOR_H
