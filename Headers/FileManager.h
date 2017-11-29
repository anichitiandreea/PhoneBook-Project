#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <fstream>
#include "../Interfaces/IPerson.h"

using namespace std;

class FileManager
{
    static string filename;
    static fstream file;
    static bool Initialized;
public:
    FileManager();
    static void Initialize(string);
    static void Close();
    template<class T>
    static void RegisterSave(T&);
    static fstream* GetSingletone();
    static void ResetFile();
};

#endif // FILE_H_INCLUDED
