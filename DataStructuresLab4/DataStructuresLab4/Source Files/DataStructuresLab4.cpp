#include <iostream>
#include <clocale>
#include "../Header Files/Dictionary.h"
#include "../Header Files/IODictionary.h"

//! \brief Точка входа в программу.
int main()
{
    //! \brief Настройка локали для корректного отображения кириллицы.
    setlocale(LC_ALL, "Russian");

    //! \brief Создание объекта словаря (внутри него создастся HashTable).
    Dictionary* dictionary = new Dictionary();

    //! \brief Запуск интерактивного меню словаря.
    IODictionary::RunDictionaryMenu(dictionary);

    //! \brief Освобождение памяти перед выходом.
    delete dictionary;

    return 0;
}