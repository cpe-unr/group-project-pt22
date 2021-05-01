#ifndef WAV_PROCESSOR_H
#define WAV_PROCESSOR_H

#include <QMainWindow>
#include <filemanager.h>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class Wav_Processor; }
QT_END_NAMESPACE

class Wav_Processor : public QMainWindow
{
    Q_OBJECT
    FileManager* fileM;
public:
    Wav_Processor(QWidget *parent = nullptr);
    Wav_Processor(QWidget *parent = nullptr, FileManager *fileManager = nullptr);
    ~Wav_Processor();

private slots:
    void on_FileButton_clicked();
    void on_LoadButton_clicked();

    void on_DockedFiles_itemClicked(QListWidgetItem *item);

private:
    Ui::Wav_Processor *ui;


    void updateFileList();
};
#endif // WAV_PROCESSOR_H
