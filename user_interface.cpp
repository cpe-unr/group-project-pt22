#include "user_interface.h"
#include "ui_Wav_Processor.h"
#include <QTextStream>
#include <QtDebug>
#include <QFileDialog>
Wav_Processor::Wav_Processor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
    this->on_FileButton_clicked();
}

Wav_Processor::Wav_Processor(QWidget *parent, FileManager *fileManager) : QMainWindow(parent), fileM(fileManager), ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
    this->on_FileButton_clicked();
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
    if(ui->FilesLayoutWidget->isVisible())
    {

        ui->DockedFiles->clear();
        ui->FilesLayoutWidget->setVisible(false);
    }
    else
    {
        ui->FilesLayoutWidget->setVisible(true);
        ui->DockedFiles->clear();
        updateFileList();


    }
}


void Wav_Processor::on_LoadButton_clicked()
{
    QFile newFile(QDir("ProcessorFiles").path() + "/" + "DockedFiles.txt");
    fileM->saveFilePath(newFile, QFileDialog::getOpenFileName());
    updateFileList();
}

void Wav_Processor::on_DockedFiles_itemClicked(QListWidgetItem *item)
{

}
