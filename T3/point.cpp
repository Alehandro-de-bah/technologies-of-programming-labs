#include "point.h"

namespace bahurov
{
    // Перегрузка оператора ввода для структуры Point
    std::istream& operator>>(std::istream& in, Point& point)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        int x = 0;
        int y = 0;
        in >> DelimetrIO{ '(' };
        in >> x;
        in >> DelimetrIO{ ';' };
        in >> y;
        in >> DelimetrIO{ ')' };

        if (in)
        {
            point.x = x;
            point.y = y;
        }
        else
        {
            in.setstate(std::ios::failbit);
        }
        return in;
    }
}
