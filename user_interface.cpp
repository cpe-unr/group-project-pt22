#include "user_interface.h"
#include "ui_Wav_Processor.h"
#include <QTextStream>
#include <QtDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QtMultimedia/QSound>
#include <QFile>
#include <Echo.h>
#include <Normalizer.h>
#include <Limiter.h>
#include <QMessageBox>
#include <16BitWav.h>
#include <32BitWav.h>
#include <8BitWav.h>
#include <Sorting.h>
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
    ui->PlayButton->setVisible(false);
    updateFileList();
}

Wav_Processor::~Wav_Processor()
{
    delete ui;
    delete fileM;
}

void Wav_Processor::updateFileList()
{
    ui->DockedFiles->clear();
    QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");
    std::vector<QString> FPs(fileM->readFileLines(newFile));

    fileM->setFiles(FPs);
    for(const QString& tempFilePath : FPs)
    {
        ui->DockedFiles->addItem(fileM->readFileNameFromFP(tempFilePath));
    }
}


void Wav_Processor::on_FileButton_clicked()
{
    //if(edit.getChangesMade()) return;

    ui->FileEditLayout->setVisible(false);
    ui->FileDockLayoutWidget->setVisible(true);
    ui->EditMetadataButton->setVisible(false);
    ui->PlayButton->setVisible(true);
    ui->PlayButton->setVisible(edit.getCurrentFileEdit() ? true : false);
    ui->DockedFiles->clear();
    updateFileList();
}

void Wav_Processor::on_EditButton_clicked()
{
    if(!edit.getIsOpened())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No file open to edit.");
        messageBox.setFixedSize(200,500);
        return;
    }

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

    //edit.getCurrentFileEdit()->changeMetaData("INAM", ui->ArtistName->text());

    edit.setChangesMade(true);
    edit.setIsMetaDataEdited(true);
}

void Wav_Processor::on_PlayButton_clicked()
{
   if(!ui->DockedFiles->isItemSelected(SelectedDockedItem)) return;


   int currentIdx = ui->DockedFiles->row(SelectedDockedItem);

   std::vector<QFile*> outFile = fileM->getFiles();

   QFileInfo info;
   info.setFile(*outFile.at(currentIdx));
   qDebug() << info.filePath();
   QSound::play(info.filePath());
}

void Wav_Processor::on_OpenButton_clicked()
{
    int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
    std::vector<QFile*> outFile = fileM->getFiles();
    QFileInfo info;
    info.setFile(*outFile.at(currentIdx));
    if(!ui->DockedFiles->isItemSelected(SelectedDockedItem) || !edit.OpenFileToEdit(info.filePath())) return;

    ui->PlayButton->setText("Play: " + info.fileName());
    if(ui->FileDockLayoutWidget->isVisible())
    {
        ui->PlayButton->setVisible(true);
    }


}

void Wav_Processor::on_SaveButton_clicked()
{
    if(!edit.getIsEditing()) return;

    QFile writeFile;

    int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
    std::vector<QFile*> outFile = fileM->getFiles();
    QFileInfo info;
    info.setFile(*outFile.at(currentIdx));

    QString newPath = QFileDialog::getSaveFileName() + ".wav";


    QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");

    if(fileM->saveFilePath(newFile, newPath, ".wav") && !QFile(newPath).exists()) updateFileList();

    if(edit.getIsWavProcessed())
    {
        switch(edit.getCurrentFileEdit()->waveHeader.bit_depth)
        {
            case 8:{

                qDebug() << "test4";
                BitWav8* wav = new BitWav8();

                wav->readFile("ProcessorFiles/WavFiles/Editing.wav");
                wav->writeFile(newPath);

            break;}

            case 16:{
                BitWav16* wav = new BitWav16();
                wav->readFile(info.filePath());
               // NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
                //LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
               // EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
                break;}

            case 32:{
                BitWav32* wav = new BitWav32();
                wav->readFile(info.filePath());
                //NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
               // LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
               // EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
                break;}
        }
    }


    edit.setChangesMade(false);
   /* else if(edit.getIsMetaDataEdited())
    {
        int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
        QFileInfo info;
        std::vector<QFile*> outFile = fileM->getFiles();
        info.setFile(*outFile.at(currentIdx));

        edit.getCurrentFileEdit()->writeFile(info.filePath());
    }*/
}

void Wav_Processor::on_ApplyButton_clicked()
{

    if(!ui->DockedFiles->isItemSelected(SelectedDockedItem)) return;

    int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
    std::vector<QFile*> outFile = fileM->getFiles();
    QFileInfo info;
    info.setFile(*outFile.at(currentIdx));

    float normalVal = ui->NormalizeLE->text().toFloat(),
          limitVal = ui->LimiterLE->text().toFloat(),
          echoVal = ui->EchoLE->text().toFloat();

    edit.setIsEditing(true);

    iProcessor *NormalProcessor = new Normalizer(normalVal);
    iProcessor *LimitProcessor = new Limiter(limitVal);
    iProcessor *EchoProcessor = new Echo(echoVal);


    qDebug() << echoVal;
    switch(edit.getCurrentFileEdit()->waveHeader.bit_depth)
    {
        case 8:{

            qDebug() << "test4";
            BitWav8* wav = new BitWav8();

            wav->readFile(info.filePath());
            NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());

            wav->writeFile(QDir("ProcessorFiles/WavFiles/Editing.wav").path());

        break;}

        case 16:{
            BitWav16* wav = new BitWav16();
            wav->readFile(info.filePath());
           // NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            //LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
           // EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            break;}

        case 32:{
            BitWav32* wav = new BitWav32();
            wav->readFile(info.filePath());
            //NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
           // LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
           // EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            break;}
    }

    delete NormalProcessor;
    delete LimitProcessor;
    delete EchoProcessor;
    edit.setIsWavProcessed(true);
    edit.setChangesMade(true);
}
