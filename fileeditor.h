#ifndef FILEEDITOR_H
#define FILEEDITOR_H


class FileEditor
{
private:
    bool isEditing = false;
    bool changesMade = false;
public:
    FileEditor();

    template<typename T>
    void applyProcess(T processor, unsigned char* buffer, int bufferSize);

    void changeMetadata();
};

#endif // FILEEDITOR_H
