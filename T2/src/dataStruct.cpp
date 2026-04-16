#include "dataStruct.h"

namespace bahurov
{
    // Перегрузка оператора ввода для структуры DataStruct
    std::istream& operator>>(std::istream& in, DataStruct& dest)
    {
        std::istream::sentry sentry(in);
        if (!sentry)
        {
            return in;
        }

        DataStruct input;
        bool isKey1Read = false;
        bool isKey2Read = false;
        bool isKey3Read = false;
        in >> DelimetrIO{ '(' } >> DelimetrIO{ ':' };
        while (in && !(isKey1Read && isKey2Read && isKey3Read))
        {
            std::string keyName = "";
            in >> KeyIO{ keyName };
            if (in >> DelimetrIO{ ' ' })
            {
                if (keyName == "key1" && !isKey1Read)
                {
                    in >> CharIO{ input.key1 };
                    isKey1Read = in ? true : false;
                }
                else if (keyName == "key2" && !isKey2Read)
                {
                    in >> RationalIO{ input.key2 };
                    isKey2Read = in ? true : false;
                }
                else if (keyName == "key3" && !isKey3Read)
                {
                    in >> StringIO{ input.key3 };
                    isKey3Read = in ? true : false;
                }
                else
                {
                    in.setstate(std::ios::failbit);
                }
                in >> DelimetrIO{ ':' };
            }
        }

        if ((in >> DelimetrIO{ ')' }) && isKey1Read && isKey2Read && isKey3Read)
        {
            dest = std::move(input);
        }
        return in;
    }

    // Перегрузка оператора вывода для структуры DataStruct
    std::ostream& operator<<(std::ostream& out, const DataStruct& src)
    {
        std::ostream::sentry sentry(out);
        if (!sentry)
        {
            return out;
        }
        iofmtguard fmtguard(out);

        out << "(:key1 ";
        out << "'" << src.key1 << "'";
        out << ":key2 (:N " << src.key2.first << ":D " << src.key2.second << ":)";
        out << ":key3 \"" << src.key3 << "\":)";

        return out;
    }

    // Перегрузка оператора < для структуры DataStruct (компаратор для std::sort)
    bool operator<(const DataStruct& lhs, const DataStruct& rhs)
    {
        if (lhs.key1 != rhs.key1)
        {
            return lhs.key1 < rhs.key1;
        }

        double lhsRational = static_cast<double>(lhs.key2.first) / lhs.key2.second;
        double rhsRational = static_cast<double>(rhs.key2.first) / rhs.key2.second;
        constexpr double EPSILON = std::numeric_limits<double>::epsilon();
        if (std::abs(lhsRational - rhsRational) > EPSILON)
        {
            return lhsRational < rhsRational;
        }

        return lhs.key3.size() < rhs.key3.size();
    }
}
