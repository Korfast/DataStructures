#ifndef IOHASHTABLE_H
#define IOHASHTABLE_H

#include "HashTable.h"

//! \brief Функции для визуализации хеш-таблицы.
namespace IOHashTable
{
    //! \brief Выводит структуру хеш-таблицы (корзины и цепочки коллизий).
    void Print(HashTable* table);
}

#endif