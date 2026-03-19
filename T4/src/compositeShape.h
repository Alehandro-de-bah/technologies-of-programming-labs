#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include "shape.h"
#include "exceptions.h"
#include <vector>
#include <memory>

class CompositeShape : public Shape
{
public:
    CompositeShape() = default; // Конструктор по умолчанию

    // Правило пяти
    CompositeShape(const CompositeShape& rhs) = delete;
    CompositeShape(CompositeShape&& rhs) = delete;
    CompositeShape& operator=(const CompositeShape& rhs) = delete;
    CompositeShape& operator=(CompositeShape&& rhs) = delete;
    ~CompositeShape() = default;

    // Переопределяемые методы
    double getArea() const override; // Вычисление площади составной фигуры
    Point getCenter() const override; // Вычисление центра составной фигуры
    void move(double dx, double dy) override; // Перемещение составной фигуры
    void scale(double k) override; // Масштабирование составной фигуры
    const char* getName() const override; // Информация о названии составной фигуры
    void printInfo() const override; // Вывод информайии о составной фигуре

    void addShape(std::unique_ptr<Shape> shape); // Добавление фигуры
private:
    std::vector<std::unique_ptr<Shape>> shapes_; // Вектор фигур
    static constexpr const char* NAME_OF_FIGURE = "COMPOSITE"; // Название составной фигуры
};

#endif
