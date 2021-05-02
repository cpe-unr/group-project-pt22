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

bool FileManager::saveFilePath(QFile &writeFile, QString filePath, QString fileType)
{
    QString type;

    int fileTypeIdx = filePath.size() - fileType.size();
    for(int i = fileTypeIdx; i < filePath.size(); i++)
    {
        type += filePath[i];
    }
    if(type == fileType)
    {
        if(writeFile.open(QFile::ReadWrite | QFile::Append))
        {
            QTextStream out(&writeFile);
            out << filePath << "\n";
            writeFile.flush();
            writeFile.close();
        }
        return true;
   }
   else
   {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","File is not of type '.wav'");
        messageBox.setFixedSize(500,200);
        return false;
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

void FileManager::removeFilePathFromFile(QFile& file, QString fileName)
{

    std::vector<QString> pathStorage;

    if(file.open(QIODevice::ReadOnly))
    {

        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString line = in.readLine();
            QString tempName;
            if(line != "")
            {

                int idx = line.size() - fileName.size();

                qDebug() << idx << " : " << line << " : " << fileName;
                for(int i = idx; i < line.size(); i++)
                {
                    tempName += line[i];
                }
                qDebug() << tempName;
                if(tempName != fileName)
                {
                    pathStorage.push_back(line);
                }


             }
        }
        file.close();

    }

    if(file.open(QIODevice::WriteOnly | QFile::Truncate))
    {

        QTextStream out(&file);
        for(QString str : pathStorage)
        {
            out << str << "\n";
        }

        file.flush();
        file.close();

        file.close();
     }

}
