template<class T>
void FileManager::RegisterSave(T& t)
{
    if(Initialized)
        FileManager::file << t;
    Register();
}