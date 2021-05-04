#include "fileeditor.h"
#include "filemanager.h"
#include <Sorting.h>
#include <QMessageBox>
#include <QDebug>
FileEditor::FileEditor()
{

}

bool FileEditor::getIsEditing()
{
    return isEditing;
}

bool FileEditor::getChangesMade()
{
    return changesMade;
}

bool FileEditor::getIsOpened()
{
    return isOpened;
}

bool FileEditor::getIsMetaDataEdited()
{
    return isMetaDataEdited;
}

bool FileEditor::getIsWavProcessed()
{
    return isWavProcessed;
}

WavFile *FileEditor::getCurrentFileEdit()
{
    return currentFileEdit;
}

void FileEditor::setIsOpened(bool val)
{
    isOpened = val;
}

void FileEditor::setIsEditing(bool val)
{
    isEditing = val;
}

void FileEditor::setChangesMade(bool val)
{
    changesMade = val;
}

bool FileEditor::setIsMetaDataEdited(bool val)
{
    isMetaDataEdited = val;
}

bool FileEditor::setIsWavProcessed(bool val)
{
    isWavProcessed = val;
}

void FileEditor::resetEdit()
{

    warnedSave = false;
    isEditing = false;
    changesMade = false;
    isOpened = false;
    currentFileEdit = nullptr;
}

bool FileEditor::OpenFileToEdit(QString filePath)
{
    qDebug() << changesMade << ":" << warnedSave;
    if(changesMade && !warnedSave)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Warning","Changes made, save if you do not wish to lose edit. Otherwise, continue to open file.");
        messageBox.setFixedSize(200,500);
        warnedSave = true;
        return false;
    }
    else
    {
        resetEdit();
        Sorting sort;
        currentFileEdit = sort.filter(filePath);
        isOpened = true;
        return true;
    }
}
