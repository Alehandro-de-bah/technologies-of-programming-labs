#include "ellipse.h"
#include "streamGuard.h"

#define _USE_MATH_DEFINES
#include <math.h>

Ellipse::Ellipse(const Point& center, double xRadius, double yRadius) // Конструктор с параметрами
    : center_(center), xRadius_(xRadius), yRadius_(yRadius)
{
    if (xRadius_ <= 0 || yRadius_ <= 0)
    {
        throw IncorrectEllipseConstructor();
    }
}

double Ellipse::getArea() const // Вычисление площади эллипса
{
    return M_PI * xRadius_ * yRadius_;
}

Point Ellipse::getCenter() const // Вычисление центра эллипса
{
    return center_;
}

void Ellipse::move(double dx, double dy) // Перемещение эллипса
{
    center_.x_ += dx;
    center_.y_ += dy;
}

void Ellipse::scale(double k) // Масштабирование эллипса
{
    if (k < 0)
    {
        throw IncorrectScale();
    }
    xRadius_ *= k;
    yRadius_ *= k;
}

const char* Ellipse::getName() const // Информация о названии эллипса
{
    return NAME_OF_FIGURE;
}

void Ellipse::printInfo() const // Вывод информации об эллипсе
{
    StreamGuard guard(std::cout);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "[" << getName() << ",\t(" << getCenter().x_ << ", " << getCenter().y_ << "),\t" << getArea() << "]" << std::endl;
}
