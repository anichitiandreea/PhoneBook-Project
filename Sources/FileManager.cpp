#include "../Headers/FileManager.h"
#include <iostream>

fstream FileManager::file;
bool FileManager::Initialized = false;
string FileManager::filename = "";

void FileManager::Initialize(string _filename)
{
    if(!Initialized && _filename != "")
    {
        Initialized = true;
        filename = _filename;
        FileManager::file.open(filename, ios_base::app | ios::in | ios::out);
    }
}

void FileManager::Close()
{
    if(Initialized)
    {
        Initialized = false;
        FileManager::file.close();
    }
}

fstream* FileManager::GetSingletone()
{
    if(!Initialized)
        Initialize(filename);
    else
        FileManager::ResetFile();
    return &file;
}

void FileManager::ResetFile()
{
    file.clear();
    file.seekg(0, file.beg);
}

void FileManager::Register()
{
    Close();
    Initialize(filename);
}
