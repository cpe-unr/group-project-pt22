#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QDir>
#include <vector>
#include <QStringList>

class FileManager
{
private:
    std::vector<QString> filePaths;
    QString proccessorDirectory;
    QDir directory; //directory to save files to
public:
    FileManager();

    void createFile(QString Directory, QString FileName);

    bool saveFilePath(QFile &writeFile, QString filePath, QString fileType);

    std::vector<QString> getFilePaths();


    std::vector<QString> readFileLines(QFile &file);
    QString readFileNameFromFP(QString filePath);
    void setFilePaths(const std::vector<QString> &paths);
    void addFilePath(QString newPath);
    void removeFilePathFromFile(QFile& file, QString fileName);
};

#endif // FILEMANAGER_H
