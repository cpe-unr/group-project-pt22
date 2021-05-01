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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wav_Processor
{
public:
    QWidget *centralwidget;
    QWidget *FilesLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *LoadButton;
    QListWidget *DockedFiles;
    QPushButton *OpenButton;
    QPushButton *RemoveButton;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_Track;
    QLabel *Track;
    QFrame *frame_Artist;
    QLabel *ArtistName;
    QFrame *frame_AlbumName;
    QLabel *TrackName;
    QFrame *frame_Genre;
    QLabel *Genre;
    QFrame *frame_ReleaseYear;
    QLabel *ReleaseYear;
    QFrame *frame_TrackNumber;
    QLabel *TrackNumber;
    QFrame *frame_Comments;
    QLabel *Comments;
    QPushButton *PlayButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *FileButton;
    QPushButton *EditButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Wav_Processor)
    {
        if (Wav_Processor->objectName().isEmpty())
            Wav_Processor->setObjectName(QString::fromUtf8("Wav_Processor"));
        Wav_Processor->resize(614, 591);
        centralwidget = new QWidget(Wav_Processor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FilesLayoutWidget = new QWidget(centralwidget);
        FilesLayoutWidget->setObjectName(QString::fromUtf8("FilesLayoutWidget"));
        FilesLayoutWidget->setGeometry(QRect(10, 40, 251, 251));
        verticalLayout = new QVBoxLayout(FilesLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LoadButton = new QPushButton(FilesLayoutWidget);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setEnabled(true);

        verticalLayout->addWidget(LoadButton);

        DockedFiles = new QListWidget(FilesLayoutWidget);
        DockedFiles->setObjectName(QString::fromUtf8("DockedFiles"));
        DockedFiles->setSelectionRectVisible(false);

        verticalLayout->addWidget(DockedFiles);

        OpenButton = new QPushButton(FilesLayoutWidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));

        verticalLayout->addWidget(OpenButton);

        RemoveButton = new QPushButton(FilesLayoutWidget);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));

        verticalLayout->addWidget(RemoveButton);

        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setEnabled(true);
        verticalWidget->setGeometry(QRect(10, 290, 261, 201));
        verticalLayout_5 = new QVBoxLayout(verticalWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_Track = new QFrame(verticalWidget);
        frame_Track->setObjectName(QString::fromUtf8("frame_Track"));
        frame_Track->setFrameShape(QFrame::StyledPanel);
        frame_Track->setFrameShadow(QFrame::Raised);
        Track = new QLabel(frame_Track);
        Track->setObjectName(QString::fromUtf8("Track"));
        Track->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_Track);

        frame_Artist = new QFrame(verticalWidget);
        frame_Artist->setObjectName(QString::fromUtf8("frame_Artist"));
        frame_Artist->setFrameShape(QFrame::StyledPanel);
        frame_Artist->setFrameShadow(QFrame::Raised);
        ArtistName = new QLabel(frame_Artist);
        ArtistName->setObjectName(QString::fromUtf8("ArtistName"));
        ArtistName->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_Artist);

        frame_AlbumName = new QFrame(verticalWidget);
        frame_AlbumName->setObjectName(QString::fromUtf8("frame_AlbumName"));
        frame_AlbumName->setFrameShape(QFrame::StyledPanel);
        frame_AlbumName->setFrameShadow(QFrame::Raised);
        TrackName = new QLabel(frame_AlbumName);
        TrackName->setObjectName(QString::fromUtf8("TrackName"));
        TrackName->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_AlbumName);

        frame_Genre = new QFrame(verticalWidget);
        frame_Genre->setObjectName(QString::fromUtf8("frame_Genre"));
        frame_Genre->setFrameShape(QFrame::StyledPanel);
        frame_Genre->setFrameShadow(QFrame::Raised);
        Genre = new QLabel(frame_Genre);
        Genre->setObjectName(QString::fromUtf8("Genre"));
        Genre->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_Genre);

        frame_ReleaseYear = new QFrame(verticalWidget);
        frame_ReleaseYear->setObjectName(QString::fromUtf8("frame_ReleaseYear"));
        frame_ReleaseYear->setFrameShape(QFrame::StyledPanel);
        frame_ReleaseYear->setFrameShadow(QFrame::Raised);
        ReleaseYear = new QLabel(frame_ReleaseYear);
        ReleaseYear->setObjectName(QString::fromUtf8("ReleaseYear"));
        ReleaseYear->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_ReleaseYear);

        frame_TrackNumber = new QFrame(verticalWidget);
        frame_TrackNumber->setObjectName(QString::fromUtf8("frame_TrackNumber"));
        frame_TrackNumber->setFrameShape(QFrame::StyledPanel);
        frame_TrackNumber->setFrameShadow(QFrame::Raised);
        TrackNumber = new QLabel(frame_TrackNumber);
        TrackNumber->setObjectName(QString::fromUtf8("TrackNumber"));
        TrackNumber->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_TrackNumber);

        frame_Comments = new QFrame(verticalWidget);
        frame_Comments->setObjectName(QString::fromUtf8("frame_Comments"));
        frame_Comments->setFrameShape(QFrame::StyledPanel);
        frame_Comments->setFrameShadow(QFrame::Raised);
        Comments = new QLabel(frame_Comments);
        Comments->setObjectName(QString::fromUtf8("Comments"));
        Comments->setGeometry(QRect(0, 0, 253, 19));

        verticalLayout_5->addWidget(frame_Comments);

        PlayButton = new QPushButton(verticalWidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));

        verticalLayout_5->addWidget(PlayButton);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 251, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FileButton = new QPushButton(horizontalLayoutWidget);
        FileButton->setObjectName(QString::fromUtf8("FileButton"));

        horizontalLayout->addWidget(FileButton);

        EditButton = new QPushButton(horizontalLayoutWidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));

        horizontalLayout->addWidget(EditButton);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(260, 80, 291, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        textEdit_4 = new QTextEdit(gridLayoutWidget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        gridLayout->addWidget(textEdit_4, 3, 2, 1, 1);

        textEdit_2 = new QTextEdit(gridLayoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 2, 2, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 3, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 3, 3, 1, 1);

        Wav_Processor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Wav_Processor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 22));
        Wav_Processor->setMenuBar(menubar);
        statusbar = new QStatusBar(Wav_Processor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Wav_Processor->setStatusBar(statusbar);
        toolBar = new QToolBar(Wav_Processor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Wav_Processor->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Wav_Processor);

        QMetaObject::connectSlotsByName(Wav_Processor);
    } // setupUi

    void retranslateUi(QMainWindow *Wav_Processor)
    {
        Wav_Processor->setWindowTitle(QCoreApplication::translate("Wav_Processor", "Wav_Processor", nullptr));
        LoadButton->setText(QCoreApplication::translate("Wav_Processor", "Load File", nullptr));
        OpenButton->setText(QCoreApplication::translate("Wav_Processor", "Open", nullptr));
        RemoveButton->setText(QCoreApplication::translate("Wav_Processor", "Remove", nullptr));
        Track->setText(QCoreApplication::translate("Wav_Processor", "Track/Song title: ", nullptr));
        ArtistName->setText(QCoreApplication::translate("Wav_Processor", "Artist name: ", nullptr));
        TrackName->setText(QCoreApplication::translate("Wav_Processor", "Album Name: ", nullptr));
        Genre->setText(QCoreApplication::translate("Wav_Processor", "Genre:", nullptr));
        ReleaseYear->setText(QCoreApplication::translate("Wav_Processor", "Release Year: ", nullptr));
        TrackNumber->setText(QCoreApplication::translate("Wav_Processor", "Track Number:", nullptr));
        Comments->setText(QCoreApplication::translate("Wav_Processor", "Comments: ", nullptr));
        PlayButton->setText(QCoreApplication::translate("Wav_Processor", "Play File", nullptr));
        FileButton->setText(QCoreApplication::translate("Wav_Processor", "Files", nullptr));
        EditButton->setText(QCoreApplication::translate("Wav_Processor", "Edit", nullptr));
        label->setText(QCoreApplication::translate("Wav_Processor", "Amount = ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Wav_Processor", "Noise Gate", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Wav_Processor", "Normalize", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Wav_Processor", "Echo", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Wav_Processor", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wav_Processor: public Ui_Wav_Processor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAV_PROCESSOR_H
