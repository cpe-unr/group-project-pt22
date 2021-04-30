#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QDir>
#include <vector>
#include <QStringList>

class FileManager
{
private:
    QStringList filePaths;
    QString proccessorDirectory;
    QDir directory; //directory to save files to
public:
    FileManager();
    FileManager(QString fileType);

    void createFile(QString Directory, QString FileName);
    void scanDir(QDir dir);
};

#endif // FILEMANAGER_H
