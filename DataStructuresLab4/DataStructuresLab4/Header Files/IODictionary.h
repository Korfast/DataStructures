#ifndef IODICTIONARY_H
#define IODICTIONARY_H

#include "Dictionary.h"

//! \brief Класс для ввода-вывода данных словаря.
class IODictionary
{
public:
    //! \brief Запускает главное меню словаря (7 пунктов).
    static void RunDictionaryMenu(Dictionary* dictionary);

    //! \brief Выводит логическое состояние словаря (только пары).
    static void Show(Dictionary* dictionary);

    //! \brief Запускает демонстрационный сценарий заполнения.
    static void RunDemo(Dictionary* dictionary);
};

#endif