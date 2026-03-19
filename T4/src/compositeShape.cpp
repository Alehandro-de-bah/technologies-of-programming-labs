#include "compositeShape.h"
#include "streamGuard.h"
#include <iomanip>
#include <iostream>
#include <limits>

// Заводим константы для максимального и минимального чисел типа double
constexpr double MAX_DOUBLE = std::numeric_limits<double>::max();
constexpr double MIN_DOUBLE = std::numeric_limits<double>::lowest();

void CompositeShape::addShape(std::unique_ptr<Shape> shape) // Добавление фигуры
{
    shapes_.push_back(std::move(shape));
}

double CompositeShape::getArea() const // Вычисление площади составной фигуры
{
    double sumOfAreas = 0;
    for (const auto& shape : shapes_)
    {
        sumOfAreas += shape->getArea();
    }
    return sumOfAreas;
}

Point CompositeShape::getCenter() const // Вычисление центра составной фигуры
{
    if (shapes_.empty())
    {
        throw EmptyCompositeShape();
    }

    double minX = MAX_DOUBLE;
    double minY = MAX_DOUBLE;
    double maxX = MIN_DOUBLE;
    double maxY = MIN_DOUBLE;

    for (const auto& shape : shapes_)
    {
        Point center = shape->getCenter();
        minX = std::min(minX, center.x_);
        minY = std::min(minY, center.y_);
        maxX = std::max(maxX, center.x_);
        maxY = std::max(maxY, center.y_);
    }
    return Point((minX + maxX) / 2, (minY + maxY) / 2);
}

void CompositeShape::scale(double k) // Масштабирование составной фигуры
{
    if (k < 0)
    {
        throw IncorrectScale();
    }
    Point centerOfCompositeShape = getCenter();
    for (auto& shape : shapes_)
    {
        Point centerOfShape = shape->getCenter();
        double dx = centerOfShape.x_ - centerOfCompositeShape.x_;
        double dy = centerOfShape.y_ - centerOfCompositeShape.y_;
        shape->move(dx * (k - 1), dy * (k - 1));
        shape->scale(k);
    }
}

void CompositeShape::move(double dx, double dy) // Перемещение составной фигуры
{
    for (auto& shape : shapes_)
    {
        shape->move(dx, dy);
    }
}

const char* CompositeShape::getName() const // Информация о названии составной фигуры
{
    return NAME_OF_FIGURE;
}

void CompositeShape::printInfo() const // Вывод информайии о составной фигуре
{
    if (shapes_.empty())
    {
        std::cout << "[ There are no figures in CompositeShape ]" << std::endl;
    }
    else
    {
        StreamGuard guard(std::cout);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "[" << getName() << ",\t(" << getCenter().x_ << ", " <<
            getCenter().y_ << "),\t" << getArea() << ":" << std::endl;
        for (const auto& shape : shapes_)
        {
            std::cout << " ";
            shape->printInfo();
        }
        std::cout << "]" << std::endl;
    }
}
