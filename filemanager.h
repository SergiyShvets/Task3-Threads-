#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <string>
#include <list>
#include <sstream>

class FileManager
{
public:

    FileManager();
    ~FileManager() = default;

    std::list<std::string> &getFileList(const std::string &folderPath);

    void writeToFile(const std::stringstream &stream);

    int getNumOfFiles() const noexcept;

private:

    std::list<std::string> fileList;
    int numOfFiles;

};

#endif // FILEFINDER_H
