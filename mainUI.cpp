#include "user_interface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wav_Processor w;
    w.show();
    return a.exec();
}
