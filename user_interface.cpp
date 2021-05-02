#include "user_interface.h"
#include "ui_Wav_Processor.h"
#include <QTextStream>
#include <QtDebug>
#include <QFileDialog>
#include <QtMultimedia/QSound>
Wav_Processor::Wav_Processor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
    this->on_FileButton_clicked();
}

Wav_Processor::Wav_Processor(QWidget *parent, FileManager *fileManager) : QMainWindow(parent), fileM(fileManager), ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
    ui->FileDockLayoutWidget->setVisible(true);
    ui->FileEditLayout->setVisible(false);
    ui->EditMetadataButton->setVisible(false);
    ui->ApplyMetadataButton->setVisible(false);
    ui->MetadataLineEditLayout->setVisible(false);
    updateFileList();
}

Wav_Processor::~Wav_Processor()
{
    delete ui;
}

void Wav_Processor::updateFileList()
{
    ui->DockedFiles->clear();
    QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");
    std::vector<QString> test = fileM->readFileLines(newFile);
    fileM->setFilePaths(test);

    std::vector<QString> TempPaths = fileM->getFilePaths();

    for(QString str : TempPaths)
    {
        ui->DockedFiles->addItem(fileM->readFileNameFromFP(str));
    }
}


void Wav_Processor::on_FileButton_clicked()
{
        ui->FileEditLayout->setVisible(false);
        ui->FileDockLayoutWidget->setVisible(true);
        ui->EditMetadataButton->setVisible(false);
        ui->PlayButton->setVisible(true);
        ui->DockedFiles->clear();
        updateFileList();
}

void Wav_Processor::on_EditButton_clicked()
{
        ui->FileDockLayoutWidget->setVisible(false);
        ui->FileEditLayout->setVisible(true);
        ui->PlayButton->setVisible(false);
        ui->EditMetadataButton->setVisible(true);
}

void Wav_Processor::on_LoadButton_clicked()
{
    QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");
    QString openFile = QFileDialog::getOpenFileName();

    if(openFile != "")
    {
        if(fileM->saveFilePath(newFile, openFile, ".wav")) updateFileList();
    }
}

void Wav_Processor::on_DockedFiles_itemClicked(QListWidgetItem *item)
{
   SelectedDockedItem = item;

}


void Wav_Processor::on_RemoveButton_clicked()
{

    QFile deleteFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");

    if(!SelectedDockedItem) return;

    fileM->removeFilePathFromFile(deleteFile, SelectedDockedItem->text());
    qDeleteAll(ui->DockedFiles->selectedItems());
}

void Wav_Processor::on_DockedFiles_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    SelectedDockedItem = current;
}

void Wav_Processor::on_EditMetadataButton_clicked()
{
    if(ui->MDDisplayLayout->isVisible())
    {
        ui->EditMetadataButton->setVisible(false);
        ui->ApplyMetadataButton->setVisible(true);
        ui->MDDisplayLayout->setVisible(false);
        ui->MetadataLineEditLayout->setVisible(true);


        ui->AlbumNameLEdit->setText(ui->AlbumName->text());
        ui->ArtistNameLEdit->setText(ui->ArtistName->text());
        ui->CommentsLEdit->setText(ui->Comments->text());
        ui->GenreLEdit->setText(ui->Genre->text());
        ui->ReleaseYearLEdit->setText(ui->ReleaseYear->text());
        ui->TrackLEdit->setText(ui->Track->text());
        ui->TrackNumberLEdit->setText(ui->TrackNumber->text());
    }
}

void Wav_Processor::on_ApplyMetadataButton_clicked()
{

    if(!ui->MetadataLineEditLayout->isVisible()) return;


    ui->ApplyMetadataButton->setVisible(false);
    ui->EditMetadataButton->setVisible(true);
    ui->MetadataLineEditLayout->setVisible(false);
    ui->MDDisplayLayout->setVisible(true);

    ui->AlbumName->setText(ui->AlbumNameLEdit->text());
    ui->ArtistName->setText(ui->ArtistNameLEdit->text());
    ui->Comments->setText(ui->CommentsLEdit->text());
    ui->Genre->setText(ui->GenreLEdit->text());
    ui->ReleaseYear->setText(ui->ReleaseYearLEdit->text());
    ui->Track->setText(ui->TrackLEdit->text());
    ui->TrackNumber->setText(ui->TrackNumberLEdit->text());

}

void Wav_Processor::on_PlayButton_clicked()
{
    //QString path = SelectedDockedItem->text();
    QSound::play("/home/pearson/CS202/yes-8-bit-stereo.wav");
}
