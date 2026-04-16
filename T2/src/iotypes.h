#ifndef IOTYPES_H
#define IOTYPES_H

#include "iofmtguard.h"
#include <iostream>
#include <string>

namespace bahurov
{
    // Структура разделителя
    struct DelimetrIO
    {
        // Ожидаемый символ-разделитель
        char exp;
    };

    // Структура символа [CHR LIT]
    struct CharIO
    {
        // Ссылка на символ, куда сохранить результат
        char& ref;
    };

    // Структура рационального числа [RAT LSP]
    struct RationalIO
    {
        // Ссылку на пару чисел
        std::pair<long long, unsigned long long>& ref;
    };

    // Структура строки
    struct StringIO
    {
        // Ссылка на строку
        std::string& ref;
    };

    // Структура имени ключа
    struct KeyIO
    {
        // Ссылка на строку, куда сохранить имя ключа
        std::string& ref;
    };

    // Перегрузка оператора ввода для структуры DelimetrIO
    std::istream& operator>>(std::istream& in, DelimetrIO&& dest);
    // Перегрузка оператора ввода для структуры CharIO
    std::istream& operator>>(std::istream& in, CharIO&& dest);
    // Перегрузка оператора ввода для структуры RationalIO
    std::istream& operator>>(std::istream& in, RationalIO&& dest);
    // Перегрузка оператора ввода для структуры StringIO
    std::istream& operator>>(std::istream& in, StringIO&& dest);
    // Перегрузка оператора ввода для структуры KeyIO
    std::istream& operator>>(std::istream& in, KeyIO&& dest);
}

#endif
