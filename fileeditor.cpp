#include "fileeditor.h"
#include "filemanager.h"
#include <Sorting.h>
#include <QMessageBox>
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
    warnedSave = false;
    isEditing = false;
    changesMade = false;
    isOpened = false;
    currentFileEdit = nullptr;
}

void FileEditor::OpenFileToEdit(QString filePath)
{
    if(changesMade && !warnedSave)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Warning","Changes made, save if you do not wish to lose edit. Otherwise, continue to open file.");
        messageBox.setFixedSize(200,500);
        warnedSave = true;
    }
    else
    {
        resetEdit();
        Sorting sort;
        currentFileEdit = sort.filter(filePath);
        std::cout << currentFileEdit->waveHeader.bit_depth << std::endl;
        isOpened = true;
    }
}
