#include "rectangle.h"
#include "streamGuard.h"

Rectangle::Rectangle(const Point& leftBottomCorner, const Point& rightTopCorner) // Конструктор с параметрами
    : leftBottomCorner_(leftBottomCorner), rightTopCorner_(rightTopCorner)
{
    if (leftBottomCorner_.x_ >= rightTopCorner_.x_ || leftBottomCorner_.y_ >= rightTopCorner_.y_)
    {
        throw IncorrectRectangleConstructor();
    }
}

double Rectangle::getArea() const // Вычисление площади прямоугольника
{
    double length = rightTopCorner_.x_ - leftBottomCorner_.x_;
    double width = rightTopCorner_.y_ - leftBottomCorner_.y_;
    return length * width;
}

Point Rectangle::getCenter() const // Вычисление центра прямоугольника
{
    double xCenter = (leftBottomCorner_.x_ + rightTopCorner_.x_) / 2;
    double yCenter = (leftBottomCorner_.y_ + rightTopCorner_.y_) / 2;
    return Point(xCenter, yCenter);
}

void Rectangle::move(double dx, double dy) // Перемещение прямоугольника
{
    leftBottomCorner_.x_ += dx;
    leftBottomCorner_.y_ += dy;
    rightTopCorner_.x_ += dx;
    rightTopCorner_.y_ += dy;
}

void Rectangle::scale(double k) // Масштабирование прямоугольника
{
    if (k < 0)
    {
        throw IncorrectScale();
    }
    Point center = getCenter();
    leftBottomCorner_.x_ = center.x_ - (center.x_ - leftBottomCorner_.x_) * k;
    leftBottomCorner_.y_ = center.y_ - (center.y_ - leftBottomCorner_.y_) * k;
    rightTopCorner_.x_ = center.x_ + (rightTopCorner_.x_ - center.x_) * k;
    rightTopCorner_.y_ = center.y_ + (rightTopCorner_.y_ - center.y_) * k;
}

const char* Rectangle::getName() const // Информация о названии прямоугольника
{
    return NAME_OF_FIGURE;
}

void Rectangle::printInfo() const // Вывод информации о прямоугольнике
{
    StreamGuard guard(std::cout);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "[" << getName() << ",\t(" << getCenter().x_ << ", " << getCenter().y_ << "),\t" << getArea() << "]" << std::endl;
}
