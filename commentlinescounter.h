#ifndef COMMENTLINESCOUNTER_H
#define COMMENTLINESCOUNTER_H

#include "linescounter.h"

class CommentLinesCounter : public LinesCounter
{
public:
    CommentLinesCounter();
    ~CommentLinesCounter() = default;

    void startCounter(const std::string &filePath) override;
    size_t getCounter() const noexcept override;
};

#endif // COMMENTLINESCOUNTER_H
