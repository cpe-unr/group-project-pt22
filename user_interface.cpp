#include "user_interface.h"
#include "ui_Wav_Processor.h"

Wav_Processor::Wav_Processor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wav_Processor)
{
    ui->setupUi(this);
}

Wav_Processor::~Wav_Processor()
{
    delete ui;
}

