#ifndef GEOMETRY_FUNCTIONS_H
#define GEOMETRY_FUNCTIONS_H

#include "polygon.h"

namespace bahurov
{
    // Вычисление площади многоугольника (формула Гаусса)
    double getArea(const Polygon& polygon);

    // Вычисление векторного произведения для векторов AB и AC
    int crossProduct(const Point& a, const Point& b, const Point& c);

    // Содержит ли полигон точку (метод луча)
    bool isPointInPolygon(const Polygon& polygon, const Point& point);

    // Лежит ли точка q на отрезке pr, если точки p, q, r коллинеарны
    bool isOnSegment(const Point& p, const Point& q, const Point& r);

    // Пересекаются ли два отрезка p1q1 и p2q2
    bool areSegmentsIntersecting(const Point& p1, const Point& q1, const Point& p2, const Point& q2);

    // Пересекаются ли два многоугольника (полигона)
    bool arePolygonsIntersecting(const Polygon& a, const Polygon& b);
}

#endif
