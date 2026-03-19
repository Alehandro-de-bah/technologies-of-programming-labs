#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape
{
public:
    virtual ~Shape() = default; // Деструктор
    virtual double getArea() const = 0; // Вычисление площади фигуры
    virtual Point getCenter() const = 0; // Вычисление центра фигуры
    virtual void move(double dx, double dy) = 0; // Перемещение фигуры
    virtual void scale(double k) = 0; // Масштабирование фигуры
    virtual const char* getName() const = 0; // Информация о названии фигуры
    virtual void printInfo() const = 0; // Вывод информации о фигуре
};

#endif
