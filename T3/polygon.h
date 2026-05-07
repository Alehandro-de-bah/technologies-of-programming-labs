#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <algorithm>
#include <sstream>
#include "point.h"

namespace bahurov
{
    struct Polygon
    {
        std::vector<Point> points;
    };

    // Перегрузка оператора ввода для структуры Polygon
    std::istream& operator>>(std::istream& in, Polygon& polygon);
}

#endif
