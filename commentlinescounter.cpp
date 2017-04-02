#include "commentlinescounter.h"

#include <regex>

CommentLinesCounter::CommentLinesCounter() : LinesCounter()
{
    std::cout << "Comment Lines Counter created" << std::endl;
}

void CommentLinesCounter::startCounter(const std::string &filePath)
{
    std::fstream inputFile(filePath, std::ios_base::in);

    if(!inputFile.is_open()){

        std::cout << "Can't open the file" << std::endl;
        return;
    }

    std::string line;

    bool multiLineComment = false;

    while(std::getline(inputFile, line)){

        if(line.find("//") != std::string::npos){
            counter++;
        }

        std::regex multiLineStart("[/]+.*");
        std::regex multiLineEnd(".*[/]");

        if(std::regex_match(line, multiLineStart)){

            multiLineComment = true;
        }

        if(multiLineComment == true){

            counter++;
        }

        if(std::regex_match(line, multiLineEnd)){

            multiLineComment = false;
        }
    }

    inputFile.close();
}

size_t CommentLinesCounter::getCounter() const noexcept
{
    return counter;
}
