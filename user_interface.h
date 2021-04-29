#ifndef WAV_PROCESSOR_H
#define WAV_PROCESSOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Wav_Processor; }
QT_END_NAMESPACE

class Wav_Processor : public QMainWindow
{
    Q_OBJECT

public:
    Wav_Processor(QWidget *parent = nullptr);
    ~Wav_Processor();

private slots:
    void on_FileButton_clicked();

private:
    Ui::Wav_Processor *ui;
};
#endif // WAV_PROCESSOR_H
