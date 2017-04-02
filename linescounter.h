#ifndef LINESCOUNTER_H
#define LINESCOUNTER_H

#include <iostream>
#include <fstream>
#include <string>

class LinesCounter
{
public:

    LinesCounter();
    virtual ~LinesCounter() = default;

    virtual void startCounter(const std::string &filePath) = 0;

    virtual size_t getCounter() const noexcept = 0;

protected:

    size_t counter;
};

#endif // LINESCOUNTER_H
