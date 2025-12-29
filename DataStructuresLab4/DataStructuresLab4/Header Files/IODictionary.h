#ifndef IODICTIONARY_H
#define IODICTIONARY_H

#include "Dictionary.h"

//! \brief Функции для работы с интерфейсом словаря.
namespace IODictionary
{
    //! \brief Выводит данные словаря в удобном виде.
    void Show(Dictionary* dictionary);

    //! \brief Запускает автоматический демонстрационный сценарий.
    void RunDemo(Dictionary* dictionary);
}

#endif