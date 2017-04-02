#ifndef PARSER_H
#define PARSER_H

#include "filemanager.h"

#include "linescounter.h"
#include "blanklinescounter.h"
#include "commentlinescounter.h"
#include "totallinescounter.h"

#include <memory>

class Parser
{
public:
    Parser();
    ~Parser() = default;

    void parseList();

    void startThread(std::shared_ptr<LinesCounter> counter, std::string &str);

    void setFolderPath(const std::string &value) noexcept;

private:

    std::unique_ptr<FileManager> fileManager;

    std::shared_ptr<LinesCounter> blankLines;
    std::shared_ptr<LinesCounter> commentLines;
    std::shared_ptr<LinesCounter> totalLines;

    std::string folderPath;

};

#endif // PARSER_H
