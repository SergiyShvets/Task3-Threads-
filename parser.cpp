#include "parser.h"

#include <thread>
#include <chrono>

Parser::Parser() :
    fileManager(std::make_unique<FileManager>()),
    blankLines(std::make_shared<BlankLinesCounter>()),
    commentLines(std::make_shared<CommentLinesCounter>()),
    totalLines(std::make_shared<TotalLinesCounter>()),
    folderPath("")
{

    std::cout << "Parser created" << std::endl;
}

void Parser::parseList()
{
    auto startTimer = std::chrono::high_resolution_clock::now();

    for(auto &&file : fileManager->getFileList(folderPath)){

        startThread(blankLines, file);
        startThread(commentLines, file);
        startThread(totalLines, file);
    }

    auto stopTimer = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(stopTimer - startTimer).count();

    std::stringstream outSream;

    outSream  << "Number of parsed files: " << fileManager->getNumOfFiles() << '\n'
              << "Total lines: " << totalLines->getCounter() << '\n'
              << "Blank lines: " << blankLines->getCounter() << '\n'
              << "Comment lines: " << commentLines->getCounter() << '\n'
              << "Physical lines: " << totalLines->getCounter() - (blankLines->getCounter() + commentLines->getCounter()) << '\n'
              << "Total time(ms): " << time << '\n';


    fileManager->writeToFile(outSream);

}

void Parser::startThread(std::shared_ptr<LinesCounter> counter, std::string &str)
{
    std::thread workerThread([&counter, &str](){counter->startCounter(str);});

    if(workerThread.joinable())
        workerThread.join();
}

void Parser::setFolderPath(const std::string &value) noexcept
{
    folderPath = value;
}
