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

///Wav Processor is the base UI class that stores the button input
Wav_Processor::Wav_Processor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
    this->on_FileButton_clicked();
}

///initialize and assign appropriate ui visibility values
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

///Updates the file list widget with the file paths stored in docked files
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

///When file button is clicked adjust UI to show file tab
void Wav_Processor::on_FileButton_clicked()
{
    //if(edit.getChangesMade()) return;


    ui->FileEditLayout->setVisible(false);
    ui->FileDockLayoutWidget->setVisible(true);
    ui->EditMetadataButton->setVisible(false);
    ui->PlayButton->setVisible(edit.getCurrentFileEdit() ? true : false);
    ui->DockedFiles->clear();
    updateFileList();
}

///When file button is clicked adjust UI to show edit tab
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
    ui->PlayButton->setVisible(!edit.getIsEditing() ? false : true);
    ui->EditMetadataButton->setVisible(true);
}


/**when load button is clicked prompt the user to open a file via explorer,
 * proceed to store new file path into the File list and read the file into filemanager **/
void Wav_Processor::on_LoadButton_clicked()
{
    QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");
    QString openFile = QFileDialog::getOpenFileName();

    if(openFile != "")
    {
        if(fileM->saveFilePath(newFile, openFile, ".wav")) updateFileList();
    }
}

///every time an item is selected update slected docked item
void Wav_Processor::on_DockedFiles_itemClicked(QListWidgetItem *item)
{
   SelectedDockedItem = item;

}

///calls to file manager to remove file path from docked files
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

///When edit metadata clicked, allow user to enter into fields
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

/// when apply meta data is clicked, update the text fields
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
    edit.setIsEditing(true);
    edit.setIsMetaDataEdited(true);
}

/// when play button is clicked, play currently opened wav file
void Wav_Processor::on_PlayButton_clicked()
{
   if(!ui->DockedFiles->isItemSelected(SelectedDockedItem)) return;



   int currentIdx = ui->DockedFiles->row(SelectedDockedItem);

   std::vector<QFile*> outFile = fileM->getFiles();

   QFileInfo info;
   info.setFile(*outFile.at(currentIdx));
   QSound::play(!ui->FileEditLayout->isVisible() ? info.filePath() : "ProcessorFiles/WavFiles/Editing.wav"); ///will play the current file being edited if editing
}

///loads in the metadata and preps for reading in buffer
void Wav_Processor::on_OpenButton_clicked()
{
    int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
    std::vector<QFile*> outFile = fileM->getFiles();
    QFileInfo info;
    info.setFile(*outFile.at(currentIdx));
    if(!ui->DockedFiles->isItemSelected(SelectedDockedItem) || !edit.OpenFileToEdit(info.filePath())) return;

    ui->AlbumName->setText(edit.getCurrentFileEdit()->metaDisplayer("IPRD"));
    ui->ArtistName->setText(edit.getCurrentFileEdit()->metaDisplayer("IART"));
    ui->Comments->setText(edit.getCurrentFileEdit()->metaDisplayer("ICMT"));
    ui->Genre->setText(edit.getCurrentFileEdit()->metaDisplayer("IGNR"));
    ui->ReleaseYear->setText(edit.getCurrentFileEdit()->metaDisplayer("ICRD"));
    ui->Track->setText(edit.getCurrentFileEdit()->metaDisplayer("INAM"));
    ui->TrackNumber->setText(edit.getCurrentFileEdit()->metaDisplayer("ITRK"));

    ui->PlayButton->setVisible(true);
    ui->PlayButton->setText("Play: " + info.fileName());




}

/**when pressed do one of two things.
 * 1.) If no process has been applied but metadata has changed. Change the existing files metadata
 * 2.) If process is applied create a new wav file and allow user to select directory to save.**/
void Wav_Processor::on_SaveButton_clicked()
{
    if(!edit.getIsEditing()) return;

    QFile writeFile;
    qDebug() << "test0";
    int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
    std::vector<QFile*> outFile = fileM->getFiles();
    QFileInfo info;
    info.setFile(*outFile.at(currentIdx));


    ///if wav has been processed create new file, if not save over existing metadata
    if(edit.getIsWavProcessed())
    {

        QString newPath = QFileDialog::getSaveFileName() + ".wav";


        QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");

        if(fileM->saveFilePath(newFile, newPath, ".wav") && !QFile(newPath).exists()) updateFileList();

        edit.getCurrentFileEdit()->readFile("ProcessorFiles/WavFiles/Editing.wav");
        edit.getCurrentFileEdit()->writeFile(newPath);

    }
    else if(!edit.getIsWavProcessed() && edit.getIsMetaDataEdited())
    {

         switch(edit.getCurrentFileEdit()->waveHeader.bit_depth)
         {
                case 8:{

                    BitWav8* wav = new BitWav8();
                    wav->readFile(info.filePath());

                    wav->changeMetaData("INAM", ui->TrackLEdit->text());
                    wav->changeMetaData("IART", ui->ArtistName->text());
                    wav->changeMetaData("IPRD", ui->AlbumNameLEdit->text());
                    wav->changeMetaData("IGNR", ui->GenreLEdit->text());
                    wav->changeMetaData("ICRD", ui->ReleaseYearLEdit->text());
                    wav->changeMetaData("ITRK", ui->TrackNumberLEdit->text());
                    wav->changeMetaData("ICMT", ui->CommentsLEdit->text());

                    wav->writeFile(info.filePath());
                break;}

                case 16:{
                    BitWav16* wav = new BitWav16();
                    wav->changeMetaData("INAM", ui->TrackLEdit->text());
                    wav->changeMetaData("IART", ui->ArtistName->text());
                    wav->changeMetaData("IPRD", ui->AlbumNameLEdit->text());
                    wav->changeMetaData("IGNR", ui->GenreLEdit->text());
                    wav->changeMetaData("ICRD", ui->ReleaseYearLEdit->text());
                    wav->changeMetaData("ITRK", ui->TrackNumberLEdit->text());
                    wav->changeMetaData("ICMT", ui->CommentsLEdit->text());

                    wav->writeFile(info.filePath());
                    break;}

                case 32:{
                    BitWav32* wav = new BitWav32(); wav->changeMetaData("INAM", ui->TrackLEdit->text());
                    wav->changeMetaData("IART", ui->ArtistName->text());
                    wav->changeMetaData("IPRD", ui->AlbumNameLEdit->text());
                    wav->changeMetaData("IGNR", ui->GenreLEdit->text());
                    wav->changeMetaData("ICRD", ui->ReleaseYearLEdit->text());
                    wav->changeMetaData("ITRK", ui->TrackNumberLEdit->text());
                    wav->changeMetaData("ICMT", ui->CommentsLEdit->text());

                    wav->writeFile(info.filePath());
                    break;}
            }


         //edit.getCurrentFileEdit()->writeFile(info.filePath());
    }
    updateFileList();

    edit.setChangesMade(false);
}

/**After pressing apply, depending on current file bit depth appropriate bitrate classes are created and proccessed
 * based off of the values of text fields**/
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

            qDebug() << "ATest1";
            BitWav16* wav = new BitWav16();
            wav->readFile(info.filePath());
            NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());

            wav->writeFile(QDir("ProcessorFiles/WavFiles/Editing.wav").path());

            break;}

        case 32:{
            BitWav32* wav = new BitWav32();
            wav->readFile(info.filePath());
            NormalProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            LimitProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());
            EchoProcessor->processBuffer(wav->getBuffer(), wav->getBufferSize());

            wav->writeFile(QDir("ProcessorFiles/WavFiles/Editing.wav").path());
            break;}
    }


    ui->PlayButton->setVisible(true);


    delete NormalProcessor;
    delete LimitProcessor;
    delete EchoProcessor;
    edit.setIsWavProcessed(true);
    edit.setChangesMade(true);
}

///Prompts the user to create a new file and exports current opened metadata to a CSV
void Wav_Processor::on_ExportDataToCSVButton_clicked()
{
    int currentIdx = ui->DockedFiles->row(SelectedDockedItem);
    std::vector<QFile*> outFile = fileM->getFiles();
    QFileInfo info;
    info.setFile(*outFile.at(currentIdx));


    QString newPath = QFileDialog::getSaveFileName() + ".csv";
    QFile file(newPath);
    if(file.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream stream(&file);
        stream << "INAM: " << edit.getCurrentFileEdit()->metaDisplayer("INAM") << "\n"
             << "IPRD: " << edit.getCurrentFileEdit()->metaDisplayer("IPRD") << "\n"
             << "IPRD: " << edit.getCurrentFileEdit()->metaDisplayer("IPRD") << "\n"
             << "IGNR: " << edit.getCurrentFileEdit()->metaDisplayer("IGNR") << "\n"
             << "ICRD: " << edit.getCurrentFileEdit()->metaDisplayer("ICRD") << "\n"
             << "ITRK: " << edit.getCurrentFileEdit()->metaDisplayer("ITRK") << "\n"
             << "ICMT: " << edit.getCurrentFileEdit()->metaDisplayer("ICMT") << "\n";
    }
}
