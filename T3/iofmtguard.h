#ifndef IOFMTGUARD_H
#define IOFMTGUARD_H

#include <ios>

namespace bahurov
{
    class iofmtguard
    {
    public:
        // Конструктор (сохраняет текущее состояние)
        iofmtguard(std::basic_ios<char>& s);
        // Деструктор (восстанавливает состояние)
        ~iofmtguard();
    private:
        // Ссылка на поток
        std::basic_ios<char>& s_;
        // Ширина поля
        std::streamsize width_;
        // Символ заполнения
        char fill_;
        // Точность
        std::streamsize precision_;
        // Флаги форматирования
        std::basic_ios<char>::fmtflags fmt_;
    };
}

#endif
