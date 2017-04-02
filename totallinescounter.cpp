#include "totallinescounter.h"

TotalLinesCounter::TotalLinesCounter() : LinesCounter()
{
    std::cout << "Physical Lines Counter created" << std::endl;
}

void TotalLinesCounter::startCounter(std::string &filePath)
{
    std::fstream inputFile(filePath, std::ios_base::in);

    if(!inputFile.is_open()){

        std::cout << "Can't open the file" << std::endl;
        return;
    }

    std::string line;

    while(std::getline(inputFile, line)){

            counter++;
    }

    inputFile.close();
}

size_t TotalLinesCounter::getCounter() const noexcept
{
    return counter;
}
