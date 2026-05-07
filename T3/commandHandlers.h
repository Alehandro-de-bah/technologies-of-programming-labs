#ifndef COMMAND_HANDLERS_H
#define COMMAND_HANDLERS_H

#include <numeric>
#include <limits>
#include <iomanip>
#include "polygon.h"
#include "constants.h"
#include "geometryFunctions.h"

namespace bahurov
{
    // Обработка команд
    // Обработка команды AREA
    void handleArea(const std::vector<Polygon>& polygons, std::istream& in);

    // Обработка команды MAX
    void handleMax(const std::vector<Polygon>& polygons, std::istream& in);

    // Обработка команды MIN
    void handleMin(const std::vector<Polygon>& polygons, std::istream& in);

    // Обработка команды COUNT
    void handleCount(const std::vector<Polygon>& polygons, std::istream& in);

    // Обработка команды LESSAREA
    void handleLessArea(const std::vector<Polygon>& polygons, std::istream& in);

    // Обработка команды INTERSECTIONS
    void handleIntersections(const std::vector<Polygon>& polygons, std::istream& in);


    // Обработка команд с конкретными параметрами
    // Обработка команды AREA EVEN
    void handleAreaEven(const std::vector<Polygon>& polygons);

    // Обработка команды AREA ODD
    void handleAreaOdd(const std::vector<Polygon>& polygons);

    // Обработка команды AREA MEAN
    void handleAreaMean(const std::vector<Polygon>& polygons);

    // Обработка команды AREA <num-of-vertexes>
    void handleAreaNumOfVertexes(const std::vector<Polygon>& polygons, const std::string& parameter);

    // Обработка команды MAX AREA
    void handleMaxArea(const std::vector<Polygon>& polygons);

    // Обработка команды MAX <num-of-vertexes>
    void handleMaxVertexes(const std::vector<Polygon>& polygons);

    // Обработка команды MIN AREA
    void handleMinArea(const std::vector<Polygon>& polygons);

    // Обработка команды MIN <num-of-vertexes>
    void handleMinVertexes(const std::vector<Polygon>& polygons);

    // Обработка команды COUNT EVEN
    void handleCountEven(const std::vector<Polygon>& polygons);

    // Обработка команды COUNT ODD
    void handleCountOdd(const std::vector<Polygon>& polygons);

    // Обработка команды COUNT <num-of-vertexes>
    void handleCountNumOfVertexes(const std::vector<Polygon>& polygons, const std::string& parameter);
}

#endif
