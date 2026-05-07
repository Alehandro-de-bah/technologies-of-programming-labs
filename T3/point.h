#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "iotypes.h"

namespace bahurov
{
    struct Point
    {
        int x;
        int y;
    };

    // Перегрузка оператора ввода для структуры Point
    std::istream& operator>>(std::istream& in, Point& point);
}

#endif
