#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "exceptions.h"
#include <iostream>
#include <iomanip>

class Rectangle : public Shape
{
public:
    Rectangle(const Point& leftBottomCorner, const Point& rightTopCorner); // Конструктор с параметрами

    // Правило пяти
    Rectangle(const Rectangle& rhs) = delete;
    Rectangle(Rectangle&& rhs) = delete;
    Rectangle& operator=(const Rectangle& rhs) = delete;
    Rectangle& operator=(Rectangle&& rhs) = delete;
    ~Rectangle() = default;

    // Переопределяемые методы
    double getArea() const override; // Вычисление площади прямоугольника
    Point getCenter() const override; // Вычисление центра прямоугольника
    void move(double dx, double dy) override; // Перемещение прямоугольника
    void scale(double k) override; // Масштабирование прямоугольника
    const char* getName() const override; // Информация о названии прямоугольника
    void printInfo() const override; // Вывод информации о прямоугольнике
private:
    Point leftBottomCorner_; // Левый нижний угол
    Point rightTopCorner_; // Правый верхний угол
    static constexpr const char* NAME_OF_FIGURE = "RECTANGLE"; // Название прямоугольника
};

#endif
