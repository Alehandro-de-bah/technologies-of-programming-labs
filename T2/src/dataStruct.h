#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <iostream>
#include <limits>
#include "iotypes.h"
#include "iofmtguard.h"

namespace bahurov
{
    struct DataStruct
    {
        // Символ [CHR LIT]
        char key1 = '\0';
        // Рациональное число [RAT LSP]
        std::pair<long long, unsigned long long> key2;
        // Строка
        std::string key3;
    };

    // Перегрузка оператора ввода для структуры DataStruct
    std::istream& operator>>(std::istream& in, DataStruct& dest);
    // Перегрузка оператора вывода для структуры DataStruct
    std::ostream& operator<<(std::ostream& out, const DataStruct& src);
    // Перегрузка оператора < для структуры DataStruct (компаратор для std::sort)
    bool operator<(const DataStruct& lhs, const DataStruct& rhs);
}

#endif
