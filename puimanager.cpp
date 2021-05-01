#include "puimanager.h"

PUIManager::PUIManager()
{

}
PUIManager::PUIManager(FileManager fm) : fileM(fm)
{

}

FileManager PUIManager::getFileManager()
{
    return fileM;
}

void PUIManager::setFileManager(FileManager fm)
{
    fileM = fm;
}
