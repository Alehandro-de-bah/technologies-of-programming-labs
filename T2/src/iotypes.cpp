#include "iotypes.h"

namespace bahurov
{
    // Перегрузка оператора ввода для структуры DelimetrIO
    std::istream& operator>>(std::istream& in, DelimetrIO&& dest)
    {
        iofmtguard fmtguard(in);

        in >> std::noskipws;

        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        char c = '0';
        in >> c;
        if (in && (c != dest.exp))
        {
            in.setstate(std::ios::failbit);
        }
        return in;
    }

    // Перегрузка оператора ввода для структуры CharIO
    std::istream& operator>>(std::istream& in, CharIO&& dest)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        char c = '0';
        in >> DelimetrIO{ '\'' } >> c >> DelimetrIO{ '\'' };
        if (in)
        {
            dest.ref = c;
        }
        else
        {
            in.setstate(std::ios::failbit);
        }
        return in;
    }

    // Перегрузка оператора ввода для структуры RationalIO
    std::istream& operator>>(std::istream& in, RationalIO&& dest)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        long long numerator = 0;
        unsigned long long denominator = 0;

        in >> DelimetrIO{ '(' } >> DelimetrIO{ ':' } >> DelimetrIO{ 'N' } >> DelimetrIO{ ' ' } >> numerator;
        in >> DelimetrIO{ ':' } >> DelimetrIO{ 'D' } >> DelimetrIO{ ' ' } >> denominator >> DelimetrIO{ ':' } >> DelimetrIO{ ')' };

        if (in && denominator != 0)
        {
            dest.ref = std::make_pair(numerator, denominator);
        }
        else
        {
            in.setstate(std::ios::failbit);
        }
        return in;
    }

    // Перегрузка оператора ввода для структуры StringIO
    std::istream& operator>>(std::istream& in, StringIO&& dest)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }
        // Считаем строку до закрывающей кавычки
        return std::getline(in >> DelimetrIO{ '"' }, dest.ref, '"');
    }

    // Перегрузка оператора ввода дл¤ структуры KeyIO
    std::istream& operator>>(std::istream& in, KeyIO&& dest)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        in >> dest.ref;

        bool isKeyCorrect = dest.ref == "key1" || dest.ref == "key2" || dest.ref == "key3";
        if (!(in && isKeyCorrect))
        {
            in.setstate(std::ios::failbit);
        }
        return in;
    }
}
