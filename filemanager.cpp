#include "filemanager.h"
#include <QDebug>
#include <QDirIterator>

FileManager::FileManager()
{

}

FileManager::FileManager(QString fileType)
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

   scanDir(directory);
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

void FileManager::scanDir(QDir dir)
{
}
