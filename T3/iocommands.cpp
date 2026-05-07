#include "iocommands.h"

namespace bahurov
{
    void readFiguresFromFile(std::ifstream& file, std::vector<Polygon>& figures)
    {
        {
            while (!file.eof())
            {
                std::copy(
                    std::istream_iterator<Polygon>(file),
                    std::istream_iterator<Polygon>(),
                    std::back_inserter(figures)
                );
                if (!file.eof() && file.fail())
                {
                    file.clear();
                }
            }

            file.close();
        }
    }

    void runCommandProcessing(std::istream& in, std::vector<Polygon>& figures)
    {
        while (!in.eof())
        {
            std::string command;
            in >> command;
            if (command == CMD_AREA)
            {
                handleArea(figures, in);
            }
            else if (command == CMD_MAX)
            {
                handleMax(figures, in);
            }
            else if (command == CMD_MIN)
            {
                handleMin(figures, in);
            }
            else if (command == CMD_COUNT)
            {
                handleCount(figures, in);
            }
            else if (command == CMD_LESSAREA)
            {
                handleLessArea(figures, in);
            }
            else if (command == CMD_INTERSECTIONS)
            {
                handleIntersections(figures, in);
            }
            else if (!in.eof())
            {
                std::cout << INVALID_COMMAND << '\n';
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}
