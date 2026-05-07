#ifndef IOCOMMANDS_H
#define IOCOMMANDS_H

#include <fstream>
#include <iterator>
#include <limits>
#include <sstream>
#include "commandHandlers.h"

namespace bahurov
{
    void readFiguresFromFile(std::ifstream& file, std::vector<Polygon>& figures);
    void runCommandProcessing(std::istream& in, std::vector<Polygon>& figures);
}

#endif
