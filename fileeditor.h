#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include <WavFile.h>
#include <QString>
class FileEditor
{
private:
    bool isEditing = false;
    bool changesMade = false;
    bool warnedSave = false;
    bool isMetaDataEdited = false;
    bool isWavProcessed= false;
    bool isOpened = false;
    WavFile* currentFileEdit;
public:
    FileEditor();

    bool getIsEditing();
    bool getChangesMade();
    bool getIsOpened();
    bool getIsMetaDataEdited();
    bool getIsWavProcessed();
    WavFile* getCurrentFileEdit();

    void setIsOpened(bool val);
    void setIsEditing(bool val);
    void setChangesMade(bool val);
    bool setIsMetaDataEdited(bool val);
    bool setIsWavProcessed(bool val);

    void resetEdit();

    void changeMetadata();
    bool OpenFileToEdit(QString filePath);
};

#endif // FILEEDITOR_H
