#include "commandHandlers.h"

namespace bahurov
{
    // Обработка команды AREA EVEN
    void handleAreaEven(const std::vector<Polygon>& polygons)
    {
        double sum = std::accumulate(polygons.cbegin(), polygons.cend(), 0.0,
            [](double acc, const Polygon& p)
            {
                return acc + (p.points.size() % 2 == 0 ? getArea(p) : 0.0);
            });
        std::cout << sum << '\n';
    }

    // Обработка команды AREA ODD
    void handleAreaOdd(const std::vector<Polygon>& polygons)
    {
        double sum = std::accumulate(polygons.begin(), polygons.end(), 0.0,
            [](double acc, const Polygon& p)
            {
                return acc + (p.points.size() % 2 != 0 ? getArea(p) : 0.0);
            });
        std::cout << sum << '\n';
    }

    // Обработка команды AREA MEAN
    void handleAreaMean(const std::vector<Polygon>& polygons)
    {
        if (!polygons.empty())
        {
            double sum = std::accumulate(polygons.begin(), polygons.end(), 0.0,
                [](double acc, const Polygon& p) { return acc + getArea(p); });
            std::cout << sum / polygons.size() << '\n';
        }
        else
        {
            std::cout << INVALID_COMMAND << '\n';
        }
    }

    // Обработка команды AREA <num-of-vertexes>
    void handleAreaNumOfVertexes(const std::vector<Polygon>& polygons, const std::string& parameter)
    {
        try
        {
            size_t n = std::stoull(parameter);

            if (n < 3)
            {
                std::cout << INVALID_COMMAND << '\n';
                return;
            }

            double sum = std::accumulate(polygons.begin(), polygons.end(), 0.0,
                [n](double acc, const Polygon& p)
                {
                    return acc + (p.points.size() == n ? getArea(p) : 0.0);
                });
            std::cout << sum << '\n';
        }
        catch (...)
        {
            std::cout << INVALID_COMMAND << '\n';
        }
    }

    // Обработка команды AREA
    void handleArea(const std::vector<Polygon>& polygons, std::istream& in)
    {
        iofmtguard fmtguard(std::cout);

        std::string parameter;
        in >> parameter;

        std::cout << std::fixed << std::setprecision(1);
        if (parameter == PARAM_EVEN)
        {
            handleAreaEven(polygons);
        }
        else if (parameter == PARAM_ODD)
        {
            handleAreaOdd(polygons);
        }
        else if (parameter == PARAM_MEAN)
        {
            handleAreaMean(polygons);
        }
        else
        {
            handleAreaNumOfVertexes(polygons, parameter);
        }
    }

    // Обработка команды MAX AREA
    void handleMaxArea(const std::vector<Polygon>& polygons)
    {
        auto it = std::max_element(polygons.begin(), polygons.end(),
            [](const Polygon& lhs, const Polygon& rhs)
            {
                return getArea(lhs) < getArea(rhs);
            });
        std::cout << getArea(*it) << '\n';
    }

    // Обработка команды MAX VERTEXES
    void handleMaxVertexes(const std::vector<Polygon>& polygons)
    {
        auto it = std::max_element(polygons.begin(), polygons.end(),
            [](const Polygon& lhs, const Polygon& rhs)
            {
                return lhs.points.size() < rhs.points.size();
            });
        std::cout << it->points.size() << '\n';
    }

    // Обработка команды MAX
    void handleMax(const std::vector<Polygon>& polygons, std::istream& in)
    {
        if (polygons.empty())
        {
            std::cout << INVALID_COMMAND << '\n';
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        iofmtguard fmtguard(std::cout);

        std::string parameter;
        in >> parameter;
        std::cout << std::fixed << std::setprecision(1);
        if (parameter == CMD_AREA)
        {
            handleMaxArea(polygons);
        }
        else if (parameter == PARAM_VERTEXES)
        {
            handleMaxVertexes(polygons);
        }
        else
        {
            std::cout << INVALID_COMMAND << '\n';
        }
    }

    // Обработка команды MIN AREA
    void handleMinArea(const std::vector<Polygon>& polygons)
    {
        auto it = std::min_element(polygons.begin(), polygons.end(),
            [](const Polygon& lhs, const Polygon& rhs)
            {
                return getArea(lhs) < getArea(rhs);
            });
        std::cout << getArea(*it) << '\n';
    }

    // Обработка команды MIN VERTEXES
    void handleMinVertexes(const std::vector<Polygon>& polygons)
    {
        auto it = std::min_element(polygons.begin(), polygons.end(),
            [](const Polygon& lhs, const Polygon& rhs)
            {
                return lhs.points.size() < rhs.points.size();
            });
        std::cout << it->points.size() << '\n';
    }

    // Обработка команды MIN
    void handleMin(const std::vector<Polygon>& polygons, std::istream& in)
    {
        if (polygons.empty())
        {
            std::cout << INVALID_COMMAND << '\n';
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        iofmtguard fmtguard(std::cout);

        std::string parameter;
        in >> parameter;
        std::cout << std::fixed << std::setprecision(1);
        if (parameter == PARAM_AREA)
        {
            handleMinArea(polygons);
        }
        else if (parameter == PARAM_VERTEXES)
        {
            handleMinVertexes(polygons);
        }
        else
        {
            std::cout << INVALID_COMMAND << '\n';
        }
    }

    // Обработка команды COUNT EVEN
    void handleCountEven(const std::vector<Polygon>& polygons)
    {
        auto count = std::count_if(polygons.begin(), polygons.end(),
            [](const Polygon& p) { return p.points.size() % 2 == 0; });
        std::cout << count << '\n';
    }

    // Обработка команды COUNT ODD
    void handleCountOdd(const std::vector<Polygon>& polygons)
    {
        auto count = std::count_if(polygons.begin(), polygons.end(),
            [](const Polygon& p) { return p.points.size() % 2 != 0; });
        std::cout << count << '\n';
    }

    // Обработка команды COUNT <num-of-vertexes>
    void handleCountNumOfVertexes(const std::vector<Polygon>& polygons, const std::string& parameter)
    {
        try
        {
            size_t n = std::stoull(parameter);

            if (n < 3)
            {
                std::cout << INVALID_COMMAND << '\n';
                return;
            }

            auto count = std::count_if(polygons.begin(), polygons.end(),
                [n](const Polygon& p) { return p.points.size() == n; });
            std::cout << count << '\n';
        }
        catch (...)
        {
            std::cout << INVALID_COMMAND << '\n';
        }
    }

    // Обработка команды COUNT
    void handleCount(const std::vector<Polygon>& polygons, std::istream& in)
    {
        std::string parameter;
        in >> parameter;

        if (parameter == PARAM_EVEN)
        {
            handleCountEven(polygons);
        }
        else if (parameter == PARAM_ODD)
        {
            handleCountOdd(polygons);
        }
        else
        {
            handleCountNumOfVertexes(polygons, parameter);
        }
    }

    // Обработка команды LESSAREA
    void handleLessArea(const std::vector<Polygon>& polygons, std::istream& in)
    {
        Polygon target;
        in >> target;
        if (in)
        {
            double targetArea = getArea(target);
            auto count = std::count_if(polygons.begin(), polygons.end(),
                [targetArea](const Polygon& p) { return getArea(p) < targetArea; });
            std::cout << count << '\n';
        }
        else
        {
            std::cout << INVALID_COMMAND << '\n';
            in.clear();
        }
    }

    // Обработка команды INTERSECTIONS
    void handleIntersections(const std::vector<Polygon>& polygons, std::istream& in)
    {
        Polygon target;
        in >> target;
        if (in)
        {
            auto count = std::count_if(polygons.begin(), polygons.end(),
                [&target](const Polygon& p) { return arePolygonsIntersecting(p, target); });
            std::cout << count << '\n';
        }
        else
        {
            std::cout << INVALID_COMMAND << '\n';
            in.clear();
        }
    }
}
