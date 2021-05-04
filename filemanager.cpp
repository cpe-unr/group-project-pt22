#include "filemanager.h"
#include <QDebug>
#include <QDirIterator>
#include <QMessageBox>
#include <QTextStream>

///Constructor that creates a directory and txt file to store file paths if not already created
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

///creates a new file in a directory
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
///Saves a file path of a file type into a txt file that stores paths
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

std::vector<QFile*> FileManager::getFiles()
{
    return files;
}

///returns out each line in a current file
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

///gets a file name from its long path
QString FileManager::readFileNameFromFP(QString filePath)
{
    QFileInfo fileInfo(filePath);
    QString fileName(fileInfo.fileName());
    return fileName;
}

///sets and creates the current files of class to a vector of paths passed in
void FileManager::setFiles(const std::vector<QString> &paths)
{
    files.clear();
    for(const QString&  str : paths)
    {
        QFile* newFP = new QFile(str);
        files.push_back(newFP);
    }
}

///removes a file from a txt file of paths
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

                for(int i = idx; i < line.size(); i++)
                {
                    tempName += line[i];
                }
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

