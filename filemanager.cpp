#include "filemanager.h"

#include <regex>
#include <iostream>
#include "boost/filesystem.hpp"
#include "boost/filesystem/path.hpp"

FileManager::FileManager() :
    numOfFiles(0)
{
    std::cout << "File Finder created" << std::endl;

}

std::list<std::string> &FileManager::getFileList(const std::string &folderPath)
{
    if(!folderPath.empty()){

        boost::filesystem::path path(folderPath);
        boost::filesystem::recursive_directory_iterator emptyFolder;

        for(boost::filesystem::recursive_directory_iterator iter(path);
            iter != emptyFolder; iter++){

            const boost::filesystem::path tempPath = (*iter);
            const std::string tempStr = tempPath.string();

            const std::regex expansion(".*\\.(h|hpp|c|cpp)");

            if(std::regex_match(tempStr, expansion)){

                fileList.emplace_back(tempStr);
                numOfFiles++;
            }

        }
    }

    return fileList;
}

void FileManager::writeToFile(const std::stringstream &stream)
{
    std::ofstream outFile("result.txt", std::ios_base::out);

    if(!outFile.is_open()){

        std::cout << "Can't open the file" << std::endl;
    }

    outFile << stream.rdbuf();

    outFile.close();
}

int FileManager::getNumOfFiles() const noexcept
{
    return numOfFiles;
}



