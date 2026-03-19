#include "rectangle.h"
#include "ellipse.h"
#include "compositeShape.h"

int main()
{
    try
    {
        std::vector<std::unique_ptr<Shape>> figures;

        auto compositeFigure = std::make_unique<CompositeShape>();
        compositeFigure->addShape(std::make_unique<Rectangle>(Point(1.0, 2.0), Point(5.0, 7.0)));
        compositeFigure->addShape(std::make_unique<Rectangle>(Point(0.0, 1.5), Point(3.0, 9.0)));
        compositeFigure->addShape(std::make_unique<Ellipse>(Point(2.5, 3.5), 7.0, 4.0));

        // Добавляем составную фигуру
        figures.push_back(std::move(compositeFigure));

        // Добавляем простые фигуры (прямоугольники и эллипсы)
        figures.push_back(std::make_unique<Rectangle>(Point(0.4, 1.1), Point(4.3, 8.9)));
        figures.push_back(std::make_unique<Rectangle>(Point(1.3, 3.6), Point(6.6, 6.7)));
        figures.push_back(std::make_unique<Ellipse>(Point(2.45, 4.15), 7.24, 3.14));
        figures.push_back(std::make_unique<Ellipse>(Point(2.8, 5.7), 8.4, 5.1));

        std::cout << "===== Information about figures before 2x increase =====" << std::endl;
        for (size_t i = 0; i < figures.size(); i++)
        {
            figures[i]->printInfo();
        }

        for (size_t i = 0; i < figures.size(); i++)
        {
            figures[i]->scale(2.0);
        }

        std::cout << "===== Information about figures after 2x increase =====" << std::endl;
        for (size_t i = 0; i < figures.size(); i++)
        {
            figures[i]->printInfo();
        }
    }
    catch (const IncorrectRectangleConstructor& error)
    {
        std::cerr << error.what() << std::endl;
        return 1;
    }
    catch (const IncorrectScale& error)
    {
        std::cerr << error.what() << std::endl;
        return 1;
    }
    catch (const IncorrectEllipseConstructor& error)
    {
        std::cerr << error.what() << std::endl;
        return 1;
    }
    catch (const EmptyCompositeShape& error)
    {
        std::cerr << error.what() << std::endl;
        return 1;
    }
    return 0;
}
