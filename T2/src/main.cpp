#include "dataStruct.h"
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    using bahurov::DataStruct;

    std::vector<DataStruct> data;

    while (!std::cin.eof())
    {
        std::copy(
            std::istream_iterator<DataStruct>(std::cin),
            std::istream_iterator<DataStruct>(),
            std::back_inserter(data)
        );
        if (!std::cin.eof() && std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Сортируем записи через std::sort, используя собственный компаратор
    std::sort(data.begin(), data.end());

    // Выводим отсортированные записи в поток std::cout
    std::copy(
        data.begin(),
        data.end(),
        std::ostream_iterator<DataStruct>(std::cout, "\n")
    );

    return 0;
}
