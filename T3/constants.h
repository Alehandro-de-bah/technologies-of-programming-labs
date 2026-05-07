#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace bahurov
{
    // Сообщения об ошибках
    const std::string INVALID_COMMAND = "<INVALID COMMAND>";
    const std::string ERROR_INCORRECT_ARGC = "ERROR: incorrect number of arguments";
    const std::string ERROR_FILE_IS_NOT_OPENED = "ERROR: file is not opened";

    // Имена команд
    const std::string CMD_AREA = "AREA";
    const std::string CMD_MAX = "MAX";
    const std::string CMD_MIN = "MIN";
    const std::string CMD_COUNT = "COUNT";
    const std::string CMD_LESSAREA = "LESSAREA";
    const std::string CMD_INTERSECTIONS = "INTERSECTIONS";

    // Параметры команд
    const std::string PARAM_EVEN = "EVEN";
    const std::string PARAM_ODD = "ODD";
    const std::string PARAM_MEAN = "MEAN";
    const std::string PARAM_AREA = "AREA";
    const std::string PARAM_VERTEXES = "VERTEXES";
}

#endif
