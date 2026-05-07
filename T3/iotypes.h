#ifndef IOTYPES_H
#define IOTYPES_H

#include <iostream>
#include "iofmtguard.h"

namespace bahurov
{
    struct DelimetrIO
    {
        char exp;
    };

    std::istream& operator>>(std::istream& in, DelimetrIO&& dest);
}

#endif
