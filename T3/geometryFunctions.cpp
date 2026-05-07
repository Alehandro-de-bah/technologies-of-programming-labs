#include "geometryFunctions.h"

namespace bahurov
{
    // Вычисление площади многоугольника (формула Гаусса)
    double getArea(const Polygon& polygon)
    {
        if (polygon.points.size() < 3)
        {
            return 0.0;
        }

        long long area2 = 0;
        size_t n = polygon.points.size();
        for (size_t i = 0; i < n; i++)
        {
            const Point& p1 = polygon.points[i]; // (x_i, y_i)
            const Point& p2 = polygon.points[(i + 1) % n]; // (x_(i+1), y_(i+1))
            area2 += static_cast<long long>(p1.x) * p2.y - static_cast<long long>(p2.x) * p1.y;
        }
        // area2 может быть как +, так и - в зависимости от порядка обхода вершин,
        // поэтому берём модуль (std::abs)
        return std::abs(area2) / 2.0;
    }

    // Вычисление векторного произведения для векторов AB и AC
    int crossProduct(const Point& a, const Point& b, const Point& c)
    {
        // Вектор AB = (b.x - a.x, b.y - a.y)
        // Вектор AC = (c.x - a.x, c.y - a.y)
        // > 0: C слева от вектора AB (против часовой стрелки)
        // < 0: C справа от AB (по часовой стрелке)
        // = 0: A, B, C лежат на одной прямой
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    // Содержит ли полигон точку (метод луча)
    bool isPointInPolygon(const Polygon& polygon, const Point& point)
    {
        size_t n = polygon.points.size();
        bool isInside = false;

        for (size_t i = 0, j = n - 1; i < n; j = i++)
        {
            const Point& pi = polygon.points[i]; // Текущая вершина
            const Point& pj = polygon.points[j]; // Предыдущая вершина

            // Проверка пересечения луча из точки вправо с ребром многоугольника
            if (((pi.y > point.y) != (pj.y > point.y)) &&
                (point.x < (pj.x - pi.x) * (point.y - pi.y) / static_cast<double>(pj.y - pi.y) + pi.x))
            {
                isInside = !isInside;
            }
        }

        return isInside;
    }

    // Лежит ли точка q на отрезке pr, если точки p, q, r коллинеарны
    bool isOnSegment(const Point& p, const Point& q, const Point& r)
    {
        // q.x должен быть между p.x и r.x
        // q.y должен быть между p.y и r.y
        return q.x <= std::max(p.x, r.x) &&
               q.x >= std::min(p.x, r.x) &&
               q.y <= std::max(p.y, r.y) &&
               q.y >= std::min(p.y, r.y);
    }

    // Пересекаются ли два отрезка p1q1 и p2q2
    bool areSegmentsIntersecting(const Point& p1, const Point& q1, const Point& p2, const Point& q2)
    {
        int d1 = crossProduct(p1, q1, p2); // Положение p2 относительно p1q1
        int d2 = crossProduct(p1, q1, q2); // Положение q2 относительно p1q1
        int d3 = crossProduct(p2, q2, p1); // Положение p1 относительно p2q2
        int d4 = crossProduct(p2, q2, q1); // Положение q1 относительно p2q2

        // p2 и q2 находтся по разные стороны от прямой p1q1
        // p1 и q1 находтся по разные стороны от прямой p2q2
        if (d1 * d2 < 0 && d3 * d4 < 0)
        {
            return true;
        }

        if ((d1 == 0 && isOnSegment(p1, p2, q1)) || // p2 на отрезке p1q1
            (d2 == 0 && isOnSegment(p1, q2, q1)) || // q2 на отрезке p1q1
            (d3 == 0 && isOnSegment(p2, p1, q2)) || // p1 на отрезке p2q2
            (d4 == 0 && isOnSegment(p2, q1, q2)))   // q1 на отрезке p2q2
        {
            return true;
        }

        return false;
    }

    // Пересекаются ли два многоугольника (полигона)
    bool arePolygonsIntersecting(const Polygon& a, const Polygon& b)
    {
        size_t n = a.points.size();
        size_t m = b.points.size();

        // Перебираем все стороны многоугольника a
        for (size_t i = 0; i < n; i++)
        {
            const Point& a1 = a.points[i];
            const Point& a2 = a.points[(i + 1) % n];
            // Перебираем все стороны многоугольника b
            for (size_t j = 0; j < m; j++)
            {
                const Point& b1 = b.points[j];
                const Point& b2 = b.points[(j + 1) % m];
                // Проверяем, пересекаются ли две стороны a1a2 и b1b2
                if (areSegmentsIntersecting(a1, a2, b1, b2))
                {
                    return true;
                }
            }
        }

        // Находятся ли все вершины полигона a внутри полигона b
        bool isAInsideB = std::all_of(a.points.begin(), a.points.end(),
            [&b](const Point& p) { return isPointInPolygon(b, p); });
        if (isAInsideB)
        {
            return true;
        }

        // Находятся ли все вершины полигона b внутри полигона a
        bool isBInsideA = std::all_of(b.points.begin(), b.points.end(),
            [&a](const Point& p) { return isPointInPolygon(a, p); });
        if (isBInsideA)
        {
            return true;
        }

        return false;
    }
}
