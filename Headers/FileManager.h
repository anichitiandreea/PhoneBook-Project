#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <fstream>
#include "../Interfaces/IPerson.h"

using namespace std;

class FileManager
{
public:
    static fstream* GetSingletone();
    static void Close();
    static void Initialize(string);
    template<class T>
    static void RegisterSave(T&);
private:
    static string filename;
    static fstream file;
    static bool Initialized;
    static void ResetFile();
    static void Register();
};

#include "../TemplatesImpl/FileManager.tpp"

#endif // FILE_H_INCLUDED
