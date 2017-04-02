#ifndef TOTALLINESCOUNTER_H
#define TOTALLINESCOUNTER_H

#include "linescounter.h"

class TotalLinesCounter : public LinesCounter
{
public:
    TotalLinesCounter();
    ~TotalLinesCounter() = default;

    void startCounter(std::string &filePath) override;
    size_t getCounter() const noexcept override;
};

#endif // TOTALLINESCOUNTER_H
