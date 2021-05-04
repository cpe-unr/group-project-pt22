#ifndef PUIMANAGER_H
#define PUIMANAGER_H


#include <filemanager.h>

class PUIManager
{
private:
    FileManager fileM;
public:
    PUIManager();
    PUIManager(FileManager fm);

    FileManager getFileManager();

    void setFileManager(FileManager fm);
};

#endif // PUIMANAGER_H
