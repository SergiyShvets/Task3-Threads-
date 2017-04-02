#include "blanklinescounter.h"


BlankLinesCounter::BlankLinesCounter() : LinesCounter()
{
    std::cout << "Blank Lines Counter created" << std::endl;
}

void BlankLinesCounter::startCounter(const std::string &filePath)
{
    std::fstream inputFile(filePath, std::ios_base::in);

    if(!inputFile.is_open()){

        std::cout << "Can't open the file" << std::endl;
        return;
    }

    std::string line;

    while(std::getline(inputFile, line)){

        if(line.empty())
            counter++;
    }

    inputFile.close();
}

size_t BlankLinesCounter::getCounter() const noexcept
{
    return counter;
}
