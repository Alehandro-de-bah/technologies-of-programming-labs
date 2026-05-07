#include "iocommands.h"

int main(int argc, char* argv[])
{
    using namespace bahurov;

    if (argc != 2)
    {
        std::cerr << ERROR_INCORRECT_ARGC << '\n';
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << ERROR_FILE_IS_NOT_OPENED << '\n';
        return 1;
    }

    std::vector<Polygon> figures;

    readFiguresFromFile(file, figures);
    runCommandProcessing(std::cin, figures);

    return 0;
}
