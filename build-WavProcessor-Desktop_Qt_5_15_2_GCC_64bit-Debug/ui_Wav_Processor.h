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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QWidget *FileDockLayoutWidget;
    QVBoxLayout *FileDockLayout;
    QPushButton *LoadButton;
    QPushButton *RemoveButton;
    QListWidget *DockedFiles;
    QPushButton *OpenButton;
    QWidget *FileEditLayout;
    QVBoxLayout *EditLayout;
    QWidget *ParamLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *NormalizeLE;
    QLineEdit *EchoLE;
    QLineEdit *LimiterLE;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *ApplyButton;
    QPushButton *SaveButton;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *MetadataLineEditLayout;
    QGridLayout *MDLineEditLayout;
    QLineEdit *ArtistNameLEdit;
    QLabel *TrackNumber_2;
    QLineEdit *ReleaseYearLEdit;
    QLineEdit *GenreLEdit;
    QLabel *Comments_2;
    QLineEdit *TrackLEdit;
    QLineEdit *CommentsLEdit;
    QLabel *Genre_2;
    QLabel *Track_2;
    QLabel *ArtistName_2;
    QLineEdit *TrackNumberLEdit;
    QLabel *ReleaseYear_2;
    QLabel *AlbumName_2;
    QLineEdit *AlbumNameLEdit;
    QWidget *MDDisplayLayout;
    QGridLayout *gridLayout_2;
    QFrame *frame_Track_2;
    QLabel *Track_3;
    QFrame *frame_ReleaseYear_2;
    QLabel *ReleaseYear_3;
    QFrame *frame_TrackNumber;
    QLabel *TrackNumber;
    QFrame *frame_Artist_2;
    QLabel *ArtistName_3;
    QFrame *frame_TrackNumber_2;
    QLabel *TrackNumber_3;
    QFrame *frame_Track;
    QLabel *Track;
    QFrame *frame_Artist;
    QLabel *ArtistName;
    QFrame *frame_Comments_2;
    QLabel *Comments_3;
    QFrame *frame_Comments;
    QLabel *Comments;
    QFrame *frame_Genre_2;
    QLabel *Genre_3;
    QFrame *frame_ReleaseYear;
    QLabel *ReleaseYear;
    QFrame *frame_Genre;
    QLabel *Genre;
    QFrame *frame_AlbumName_2;
    QLabel *AlbumName_3;
    QFrame *frame_AlbumName;
    QLabel *AlbumName;
    QPushButton *EditMetadataButton;
    QPushButton *ApplyMetadataButton;
    QPushButton *PlayButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *FileButton;
    QPushButton *EditButton;
    QWidget *MetadataDisplayLayout;
    QVBoxLayout *MetaDataDisplayLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Wav_Processor)
    {
        if (Wav_Processor->objectName().isEmpty())
            Wav_Processor->setObjectName(QString::fromUtf8("Wav_Processor"));
        Wav_Processor->resize(667, 688);
        centralwidget = new QWidget(Wav_Processor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FilesLayoutWidget = new QWidget(centralwidget);
        FilesLayoutWidget->setObjectName(QString::fromUtf8("FilesLayoutWidget"));
        FilesLayoutWidget->setGeometry(QRect(10, 40, 291, 291));
        verticalLayout = new QVBoxLayout(FilesLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FileDockLayoutWidget = new QWidget(FilesLayoutWidget);
        FileDockLayoutWidget->setObjectName(QString::fromUtf8("FileDockLayoutWidget"));
        FileDockLayout = new QVBoxLayout(FileDockLayoutWidget);
        FileDockLayout->setObjectName(QString::fromUtf8("FileDockLayout"));
        LoadButton = new QPushButton(FileDockLayoutWidget);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setEnabled(true);

        FileDockLayout->addWidget(LoadButton);

        RemoveButton = new QPushButton(FileDockLayoutWidget);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));

        FileDockLayout->addWidget(RemoveButton);


        verticalLayout->addWidget(FileDockLayoutWidget);

        DockedFiles = new QListWidget(FilesLayoutWidget);
        DockedFiles->setObjectName(QString::fromUtf8("DockedFiles"));
        DockedFiles->setSelectionRectVisible(false);

        verticalLayout->addWidget(DockedFiles);

        OpenButton = new QPushButton(FilesLayoutWidget);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));

        verticalLayout->addWidget(OpenButton);

        FileEditLayout = new QWidget(FilesLayoutWidget);
        FileEditLayout->setObjectName(QString::fromUtf8("FileEditLayout"));
        EditLayout = new QVBoxLayout(FileEditLayout);
        EditLayout->setObjectName(QString::fromUtf8("EditLayout"));
        ParamLayout = new QWidget(FileEditLayout);
        ParamLayout->setObjectName(QString::fromUtf8("ParamLayout"));
        gridLayout = new QGridLayout(ParamLayout);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ParamLayout);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        NormalizeLE = new QLineEdit(ParamLayout);
        NormalizeLE->setObjectName(QString::fromUtf8("NormalizeLE"));

        gridLayout->addWidget(NormalizeLE, 1, 1, 1, 1);

        EchoLE = new QLineEdit(ParamLayout);
        EchoLE->setObjectName(QString::fromUtf8("EchoLE"));

        gridLayout->addWidget(EchoLE, 3, 1, 1, 1);

        LimiterLE = new QLineEdit(ParamLayout);
        LimiterLE->setObjectName(QString::fromUtf8("LimiterLE"));

        gridLayout->addWidget(LimiterLE, 2, 1, 1, 1);

        label_2 = new QLabel(ParamLayout);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 2, 1, 1);

        label_3 = new QLabel(ParamLayout);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        label_4 = new QLabel(ParamLayout);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);


        EditLayout->addWidget(ParamLayout);

        ApplyButton = new QPushButton(FileEditLayout);
        ApplyButton->setObjectName(QString::fromUtf8("ApplyButton"));

        EditLayout->addWidget(ApplyButton);

        SaveButton = new QPushButton(FileEditLayout);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        EditLayout->addWidget(SaveButton);


        verticalLayout->addWidget(FileEditLayout);

        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setEnabled(true);
        verticalWidget->setGeometry(QRect(10, 320, 291, 221));
        verticalLayout_5 = new QVBoxLayout(verticalWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        MetadataLineEditLayout = new QWidget(verticalWidget);
        MetadataLineEditLayout->setObjectName(QString::fromUtf8("MetadataLineEditLayout"));
        MDLineEditLayout = new QGridLayout(MetadataLineEditLayout);
        MDLineEditLayout->setObjectName(QString::fromUtf8("MDLineEditLayout"));
        ArtistNameLEdit = new QLineEdit(MetadataLineEditLayout);
        ArtistNameLEdit->setObjectName(QString::fromUtf8("ArtistNameLEdit"));

        MDLineEditLayout->addWidget(ArtistNameLEdit, 3, 1, 1, 1);

        TrackNumber_2 = new QLabel(MetadataLineEditLayout);
        TrackNumber_2->setObjectName(QString::fromUtf8("TrackNumber_2"));

        MDLineEditLayout->addWidget(TrackNumber_2, 0, 0, 1, 1);

        ReleaseYearLEdit = new QLineEdit(MetadataLineEditLayout);
        ReleaseYearLEdit->setObjectName(QString::fromUtf8("ReleaseYearLEdit"));

        MDLineEditLayout->addWidget(ReleaseYearLEdit, 4, 1, 1, 1);

        GenreLEdit = new QLineEdit(MetadataLineEditLayout);
        GenreLEdit->setObjectName(QString::fromUtf8("GenreLEdit"));

        MDLineEditLayout->addWidget(GenreLEdit, 1, 1, 1, 1);

        Comments_2 = new QLabel(MetadataLineEditLayout);
        Comments_2->setObjectName(QString::fromUtf8("Comments_2"));

        MDLineEditLayout->addWidget(Comments_2, 5, 0, 1, 1);

        TrackLEdit = new QLineEdit(MetadataLineEditLayout);
        TrackLEdit->setObjectName(QString::fromUtf8("TrackLEdit"));

        MDLineEditLayout->addWidget(TrackLEdit, 2, 1, 1, 1);

        CommentsLEdit = new QLineEdit(MetadataLineEditLayout);
        CommentsLEdit->setObjectName(QString::fromUtf8("CommentsLEdit"));

        MDLineEditLayout->addWidget(CommentsLEdit, 5, 1, 1, 1);

        Genre_2 = new QLabel(MetadataLineEditLayout);
        Genre_2->setObjectName(QString::fromUtf8("Genre_2"));

        MDLineEditLayout->addWidget(Genre_2, 1, 0, 1, 1);

        Track_2 = new QLabel(MetadataLineEditLayout);
        Track_2->setObjectName(QString::fromUtf8("Track_2"));

        MDLineEditLayout->addWidget(Track_2, 2, 0, 1, 1);

        ArtistName_2 = new QLabel(MetadataLineEditLayout);
        ArtistName_2->setObjectName(QString::fromUtf8("ArtistName_2"));

        MDLineEditLayout->addWidget(ArtistName_2, 3, 0, 1, 1);

        TrackNumberLEdit = new QLineEdit(MetadataLineEditLayout);
        TrackNumberLEdit->setObjectName(QString::fromUtf8("TrackNumberLEdit"));

        MDLineEditLayout->addWidget(TrackNumberLEdit, 0, 1, 1, 1);

        ReleaseYear_2 = new QLabel(MetadataLineEditLayout);
        ReleaseYear_2->setObjectName(QString::fromUtf8("ReleaseYear_2"));

        MDLineEditLayout->addWidget(ReleaseYear_2, 4, 0, 1, 1);

        AlbumName_2 = new QLabel(MetadataLineEditLayout);
        AlbumName_2->setObjectName(QString::fromUtf8("AlbumName_2"));

        MDLineEditLayout->addWidget(AlbumName_2, 6, 0, 1, 1);

        AlbumNameLEdit = new QLineEdit(MetadataLineEditLayout);
        AlbumNameLEdit->setObjectName(QString::fromUtf8("AlbumNameLEdit"));

        MDLineEditLayout->addWidget(AlbumNameLEdit, 6, 1, 1, 1);


        verticalLayout_5->addWidget(MetadataLineEditLayout);

        MDDisplayLayout = new QWidget(verticalWidget);
        MDDisplayLayout->setObjectName(QString::fromUtf8("MDDisplayLayout"));
        gridLayout_2 = new QGridLayout(MDDisplayLayout);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_Track_2 = new QFrame(MDDisplayLayout);
        frame_Track_2->setObjectName(QString::fromUtf8("frame_Track_2"));
        frame_Track_2->setFrameShape(QFrame::StyledPanel);
        frame_Track_2->setFrameShadow(QFrame::Raised);
        Track_3 = new QLabel(frame_Track_2);
        Track_3->setObjectName(QString::fromUtf8("Track_3"));
        Track_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Track_2, 2, 0, 1, 1);

        frame_ReleaseYear_2 = new QFrame(MDDisplayLayout);
        frame_ReleaseYear_2->setObjectName(QString::fromUtf8("frame_ReleaseYear_2"));
        frame_ReleaseYear_2->setFrameShape(QFrame::StyledPanel);
        frame_ReleaseYear_2->setFrameShadow(QFrame::Raised);
        ReleaseYear_3 = new QLabel(frame_ReleaseYear_2);
        ReleaseYear_3->setObjectName(QString::fromUtf8("ReleaseYear_3"));
        ReleaseYear_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_ReleaseYear_2, 4, 0, 1, 1);

        frame_TrackNumber = new QFrame(MDDisplayLayout);
        frame_TrackNumber->setObjectName(QString::fromUtf8("frame_TrackNumber"));
        frame_TrackNumber->setFrameShape(QFrame::StyledPanel);
        frame_TrackNumber->setFrameShadow(QFrame::Raised);
        TrackNumber = new QLabel(frame_TrackNumber);
        TrackNumber->setObjectName(QString::fromUtf8("TrackNumber"));
        TrackNumber->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_TrackNumber, 0, 1, 1, 1);

        frame_Artist_2 = new QFrame(MDDisplayLayout);
        frame_Artist_2->setObjectName(QString::fromUtf8("frame_Artist_2"));
        frame_Artist_2->setFrameShape(QFrame::StyledPanel);
        frame_Artist_2->setFrameShadow(QFrame::Raised);
        ArtistName_3 = new QLabel(frame_Artist_2);
        ArtistName_3->setObjectName(QString::fromUtf8("ArtistName_3"));
        ArtistName_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Artist_2, 3, 0, 1, 1);

        frame_TrackNumber_2 = new QFrame(MDDisplayLayout);
        frame_TrackNumber_2->setObjectName(QString::fromUtf8("frame_TrackNumber_2"));
        frame_TrackNumber_2->setFrameShape(QFrame::StyledPanel);
        frame_TrackNumber_2->setFrameShadow(QFrame::Raised);
        TrackNumber_3 = new QLabel(frame_TrackNumber_2);
        TrackNumber_3->setObjectName(QString::fromUtf8("TrackNumber_3"));
        TrackNumber_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_TrackNumber_2, 0, 0, 1, 1);

        frame_Track = new QFrame(MDDisplayLayout);
        frame_Track->setObjectName(QString::fromUtf8("frame_Track"));
        frame_Track->setFrameShape(QFrame::StyledPanel);
        frame_Track->setFrameShadow(QFrame::Raised);
        Track = new QLabel(frame_Track);
        Track->setObjectName(QString::fromUtf8("Track"));
        Track->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Track, 2, 1, 1, 1);

        frame_Artist = new QFrame(MDDisplayLayout);
        frame_Artist->setObjectName(QString::fromUtf8("frame_Artist"));
        frame_Artist->setFrameShape(QFrame::StyledPanel);
        frame_Artist->setFrameShadow(QFrame::Raised);
        ArtistName = new QLabel(frame_Artist);
        ArtistName->setObjectName(QString::fromUtf8("ArtistName"));
        ArtistName->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Artist, 3, 1, 1, 1);

        frame_Comments_2 = new QFrame(MDDisplayLayout);
        frame_Comments_2->setObjectName(QString::fromUtf8("frame_Comments_2"));
        frame_Comments_2->setFrameShape(QFrame::StyledPanel);
        frame_Comments_2->setFrameShadow(QFrame::Raised);
        Comments_3 = new QLabel(frame_Comments_2);
        Comments_3->setObjectName(QString::fromUtf8("Comments_3"));
        Comments_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Comments_2, 5, 0, 1, 1);

        frame_Comments = new QFrame(MDDisplayLayout);
        frame_Comments->setObjectName(QString::fromUtf8("frame_Comments"));
        frame_Comments->setFrameShape(QFrame::StyledPanel);
        frame_Comments->setFrameShadow(QFrame::Raised);
        Comments = new QLabel(frame_Comments);
        Comments->setObjectName(QString::fromUtf8("Comments"));
        Comments->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Comments, 5, 1, 1, 1);

        frame_Genre_2 = new QFrame(MDDisplayLayout);
        frame_Genre_2->setObjectName(QString::fromUtf8("frame_Genre_2"));
        frame_Genre_2->setFrameShape(QFrame::StyledPanel);
        frame_Genre_2->setFrameShadow(QFrame::Raised);
        Genre_3 = new QLabel(frame_Genre_2);
        Genre_3->setObjectName(QString::fromUtf8("Genre_3"));
        Genre_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Genre_2, 1, 0, 1, 1);

        frame_ReleaseYear = new QFrame(MDDisplayLayout);
        frame_ReleaseYear->setObjectName(QString::fromUtf8("frame_ReleaseYear"));
        frame_ReleaseYear->setFrameShape(QFrame::StyledPanel);
        frame_ReleaseYear->setFrameShadow(QFrame::Raised);
        ReleaseYear = new QLabel(frame_ReleaseYear);
        ReleaseYear->setObjectName(QString::fromUtf8("ReleaseYear"));
        ReleaseYear->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_ReleaseYear, 4, 1, 1, 1);

        frame_Genre = new QFrame(MDDisplayLayout);
        frame_Genre->setObjectName(QString::fromUtf8("frame_Genre"));
        frame_Genre->setFrameShape(QFrame::StyledPanel);
        frame_Genre->setFrameShadow(QFrame::Raised);
        Genre = new QLabel(frame_Genre);
        Genre->setObjectName(QString::fromUtf8("Genre"));
        Genre->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_Genre, 1, 1, 1, 1);

        frame_AlbumName_2 = new QFrame(MDDisplayLayout);
        frame_AlbumName_2->setObjectName(QString::fromUtf8("frame_AlbumName_2"));
        frame_AlbumName_2->setFrameShape(QFrame::StyledPanel);
        frame_AlbumName_2->setFrameShadow(QFrame::Raised);
        AlbumName_3 = new QLabel(frame_AlbumName_2);
        AlbumName_3->setObjectName(QString::fromUtf8("AlbumName_3"));
        AlbumName_3->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_AlbumName_2, 6, 0, 1, 1);

        frame_AlbumName = new QFrame(MDDisplayLayout);
        frame_AlbumName->setObjectName(QString::fromUtf8("frame_AlbumName"));
        frame_AlbumName->setFrameShape(QFrame::StyledPanel);
        frame_AlbumName->setFrameShadow(QFrame::Raised);
        AlbumName = new QLabel(frame_AlbumName);
        AlbumName->setObjectName(QString::fromUtf8("AlbumName"));
        AlbumName->setGeometry(QRect(0, 0, 253, 19));

        gridLayout_2->addWidget(frame_AlbumName, 6, 1, 1, 1);


        verticalLayout_5->addWidget(MDDisplayLayout);

        EditMetadataButton = new QPushButton(verticalWidget);
        EditMetadataButton->setObjectName(QString::fromUtf8("EditMetadataButton"));

        verticalLayout_5->addWidget(EditMetadataButton);

        ApplyMetadataButton = new QPushButton(verticalWidget);
        ApplyMetadataButton->setObjectName(QString::fromUtf8("ApplyMetadataButton"));

        verticalLayout_5->addWidget(ApplyMetadataButton);

        PlayButton = new QPushButton(verticalWidget);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));

        verticalLayout_5->addWidget(PlayButton);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 281, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FileButton = new QPushButton(horizontalLayoutWidget);
        FileButton->setObjectName(QString::fromUtf8("FileButton"));

        horizontalLayout->addWidget(FileButton);

        EditButton = new QPushButton(horizontalLayoutWidget);
        EditButton->setObjectName(QString::fromUtf8("EditButton"));

        horizontalLayout->addWidget(EditButton);

        MetadataDisplayLayout = new QWidget(centralwidget);
        MetadataDisplayLayout->setObjectName(QString::fromUtf8("MetadataDisplayLayout"));
        MetadataDisplayLayout->setGeometry(QRect(370, 200, 161, 251));
        MetaDataDisplayLayout = new QVBoxLayout(MetadataDisplayLayout);
        MetaDataDisplayLayout->setObjectName(QString::fromUtf8("MetaDataDisplayLayout"));
        Wav_Processor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Wav_Processor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 667, 22));
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
        RemoveButton->setText(QCoreApplication::translate("Wav_Processor", "Remove File", nullptr));
        OpenButton->setText(QCoreApplication::translate("Wav_Processor", "Open", nullptr));
        label->setText(QCoreApplication::translate("Wav_Processor", "Amount = ", nullptr));
        label_2->setText(QCoreApplication::translate("Wav_Processor", "Echo", nullptr));
        label_3->setText(QCoreApplication::translate("Wav_Processor", "Limit", nullptr));
        label_4->setText(QCoreApplication::translate("Wav_Processor", "Normalize", nullptr));
        ApplyButton->setText(QCoreApplication::translate("Wav_Processor", "Apply", nullptr));
        SaveButton->setText(QCoreApplication::translate("Wav_Processor", "Save", nullptr));
        TrackNumber_2->setText(QCoreApplication::translate("Wav_Processor", "Track Number:", nullptr));
        Comments_2->setText(QCoreApplication::translate("Wav_Processor", "Comments: ", nullptr));
        Genre_2->setText(QCoreApplication::translate("Wav_Processor", "Genre:", nullptr));
        Track_2->setText(QCoreApplication::translate("Wav_Processor", "Track/Song title: ", nullptr));
        ArtistName_2->setText(QCoreApplication::translate("Wav_Processor", "Artist name: ", nullptr));
        ReleaseYear_2->setText(QCoreApplication::translate("Wav_Processor", "Release Year: ", nullptr));
        AlbumName_2->setText(QCoreApplication::translate("Wav_Processor", "Album Name: ", nullptr));
        Track_3->setText(QCoreApplication::translate("Wav_Processor", "Track/Song title: ", nullptr));
        ReleaseYear_3->setText(QCoreApplication::translate("Wav_Processor", "Release Year: ", nullptr));
        TrackNumber->setText(QString());
        ArtistName_3->setText(QCoreApplication::translate("Wav_Processor", "Artist name: ", nullptr));
        TrackNumber_3->setText(QCoreApplication::translate("Wav_Processor", "Track Number:", nullptr));
        Track->setText(QString());
        ArtistName->setText(QString());
        Comments_3->setText(QCoreApplication::translate("Wav_Processor", "Comments: ", nullptr));
        Comments->setText(QString());
        Genre_3->setText(QCoreApplication::translate("Wav_Processor", "Genre:", nullptr));
        ReleaseYear->setText(QString());
        Genre->setText(QString());
        AlbumName_3->setText(QCoreApplication::translate("Wav_Processor", "Album Name: ", nullptr));
        AlbumName->setText(QString());
        EditMetadataButton->setText(QCoreApplication::translate("Wav_Processor", "Edit Metadata", nullptr));
        ApplyMetadataButton->setText(QCoreApplication::translate("Wav_Processor", "Apply Metadata", nullptr));
        PlayButton->setText(QCoreApplication::translate("Wav_Processor", "Play File", nullptr));
        FileButton->setText(QCoreApplication::translate("Wav_Processor", "Files", nullptr));
        EditButton->setText(QCoreApplication::translate("Wav_Processor", "Edit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Wav_Processor", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wav_Processor: public Ui_Wav_Processor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAV_PROCESSOR_H
