#include "../Headers/FileManager.h"
#include <iostream>

fstream FileManager::file;
bool FileManager::Initialized = false;
string FileManager::filename = "";

FileManager::FileManager()
{
}

void FileManager::Initialize(string _filename)
{
    if(!Initialized && _filename != "")
    {
        Initialized = true;
        filename = _filename;
        FileManager::file.open(filename, ios_base::app | ios::in | ios::out);
    }
}

template<class T>
void FileManager::RegisterSave(T& t)
{
    if(Initialized)
    {
        FileManager::file << t;
    }
    Close();
    Initialize(filename);
}

void FileManager::Close()
{
    Initialized = false;
    FileManager::file.close();
}

fstream* FileManager::GetSingletone()
{
    return &file;
}

void FileManager::ResetFile()
{
    file.clear();
    file.seekg(0, file.beg);
}
