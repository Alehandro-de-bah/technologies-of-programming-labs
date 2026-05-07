#include "polygon.h"

namespace bahurov
{
    // Перегрузка оператора ввода для структуры Polygon
    std::istream& operator>>(std::istream& in, Polygon& polygon)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        std::string line;
        if (!std::getline(in, line))
        {
            return in;
        }

        std::istringstream iss(line);
        size_t vertexes = 0;

        if (!(iss >> vertexes) || vertexes < 3)
        {
            in.setstate(std::ios::failbit);
            return in;
        }

        Polygon input;
        Point point;
        while (iss >> DelimetrIO{ ' ' } >> point)
        {
            input.points.push_back(std::move(point));
        }

        if (input.points.size() != vertexes)
        {
            in.setstate(std::ios::failbit);
        }
        else
        {
            polygon = std::move(input);
        }

        return in;
    }
}
