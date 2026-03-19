#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "shape.h"
#include "exceptions.h"
#include <iostream>
#include <iomanip>

class Ellipse : public Shape
{
public:
    Ellipse(const Point& center, double xRadius, double yRadius); // Конструктор с параметрами

    // Правило пяти
    Ellipse(const Ellipse& rhs) = delete;
    Ellipse(Ellipse&& rhs) = delete;
    Ellipse& operator=(const Ellipse& rhs) = delete;
    Ellipse& operator=(Ellipse&& rhs) = delete;
    ~Ellipse() = default;

    // Переопределяемые методы
    double getArea() const override; // Вычисление площади эллипса
    Point getCenter() const override; // Вычисление центра эллипса
    void move(double dx, double dy) override; // Перемещение эллипса
    void scale(double k) override; // Масштабирование эллипса
    const char* getName() const override; // Информация о названии эллипса
    void printInfo() const override; // Вывод информации об эллипсе
private:
    Point center_; // Центр эллипса
    double xRadius_; // Радиус по оси x
    double yRadius_; // Радиус по оси y
    static constexpr const char* NAME_OF_FIGURE = "ELLIPSE"; // Название эллипса
};

#endif
