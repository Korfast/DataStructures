#ifndef IOHASHTABLE_H
#define IOHASHTABLE_H

#include "HashTable.h"

//! \brief Класс для визуализации внутреннего устройства хеш-таблицы.
class IOHashTable
{
public:
    //! \brief Выводит техническое состояние: Capacity, Size, Load Factor и список корзин.
    static void Print(HashTable* table);
};

#endif