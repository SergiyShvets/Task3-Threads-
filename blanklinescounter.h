#ifndef BLANKLINESCOUNTER_H
#define BLANKLINESCOUNTER_H

#include "linescounter.h"

class BlankLinesCounter : public LinesCounter
{
public:
    BlankLinesCounter();
    ~BlankLinesCounter() = default;

    void startCounter(std::string &filePath) override;
    size_t getCounter() const noexcept override;
};

#endif // BLANKLINESCOUNTER_H
