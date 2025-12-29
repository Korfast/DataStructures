#include "../Header Files/IOHashTable.h"
#include <iostream>

void IOHashTable::Print(HashTable* table)
{
    if (!table) return;

    auto buckets = table->GetBuckets();
    std::cout << "\n--- Структура Хеш-таблицы ---" << std::endl;
    for (int i = 0; i < table->GetCapacity(); i++)
    {
        std::cout << "Корзина [" << i << "]: ";
        if (buckets[i] != nullptr)
        {
            for (const auto& pair : *buckets[i])
            {
                std::cout << "{" << pair.GetKey() << "} -> ";
            }
            std::cout << "NULL";
        }
        else
        {
            std::cout << "пусто";
        }
        std::cout << std::endl;
    }
}