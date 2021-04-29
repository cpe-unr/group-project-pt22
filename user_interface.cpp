#include "user_interface.h"
#include "ui_Wav_Processor.h"

Wav_Processor::Wav_Processor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
    this->on_FileButton_clicked();
}

Wav_Processor::~Wav_Processor()
{
    delete ui;
}


void Wav_Processor::on_FileButton_clicked()
{
    if(ui->SaveButton->isEnabled() && ui->LoadButton->isEnabled())
    {
        ui->SaveButton->setEnabled(false);
        ui->SaveButton->hide();
        ui->LoadButton->setEnabled(false);
        ui->LoadButton->hide();
    }
    else
    {
        ui->SaveButton->setEnabled(true);
        ui->SaveButton->show();
        ui->LoadButton->setEnabled(true);
        ui->LoadButton->show();
    }
}
