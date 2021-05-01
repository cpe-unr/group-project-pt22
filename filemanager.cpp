#include "filemanager.h"
#include <QDebug>
#include <QDirIterator>
#include <QMessageBox>
#include <QTextStream>
FileManager::FileManager()
{
    if(!QDir("ProcessorFiles").exists())
    {
        QDir().mkdir("ProcessorFiles");
        directory.setPath(QDir("ProcessorFiles").path());
        createFile(QDir("ProcessorFiles").path(), "DockedFiles.txt");
    }
    else
    {
         directory.setPath(QDir("ProcessorFiles").path());
         createFile(QDir("ProcessorFiles").path(), "DockedFiles.txt");
    }

}

void FileManager::createFile(QString Directory, QString FileName)
{

    QString path = Directory +  "/" + FileName;
    QFile Fout(path);

    if(!Fout.exists())
    {

        QFile newFile(path);

        if(newFile.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text))
        {

            QTextStream out(&newFile);
            out << "This file is new!\n";

        }
        newFile.close();
    }

}

void FileManager::saveFilePath(QFile &writeFile, QString filePath)
{
    if(writeFile.open(QFile::ReadWrite | QFile::Append))
    {
        QTextStream out(&writeFile);
        out << filePath << "\n";
        writeFile.flush();
        writeFile.close();
    }
}

std::vector<QString> FileManager::getFilePaths()
{
    return filePaths;
}

std::vector<QString> FileManager::readFileLines(QFile &file)
{
    std::vector<QString> outStrings;

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            outStrings.push_back(line);
        }

        file.close();
    }
    return outStrings;
}

QString FileManager::readFileNameFromFP(QString filePath)
{
    QFileInfo fileInfo(filePath);
    QString fileName(fileInfo.fileName());
    return fileName;
}

void FileManager::setFilePaths(const std::vector<QString> &paths)
{
    filePaths.clear();
    for(QString str : paths)
    {
        filePaths.push_back(str);
    }


}
