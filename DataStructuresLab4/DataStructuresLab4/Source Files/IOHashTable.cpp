#include "../Header Files/IOHashTable.h"
#include <iostream>
#include <iomanip>

void IOHashTable::Print(HashTable* table)
{
    if (!table) return;

    int capacity = table->GetCapacity();
    int size = table->GetSize();
    double loadFactor = static_cast<double>(size) / capacity;
    auto buckets = table->GetBuckets();

    std::cout << "\n=== Состояние хеш-таблицы ===" << std::endl;
    std::cout << "Емкость (Capacity): " << capacity << std::endl;
    std::cout << "Размер (Size): " << size << std::endl;
    std::cout << "Коэффициент загрузки (Load Factor): " << std::fixed << std::setprecision(2) << loadFactor << std::endl;

    std::cout << "\nПары ключ-значение:" << std::endl;

    for (int i = 0; i < capacity; i++)
    {
        // Выравнивание индекса [  0]
        std::cout << "[" << std::setw(3) << i << "]: ";

        if (buckets[i] == nullptr || buckets[i]->empty())
        {
            std::cout << "ПУСТО (EMPTY)";
        }
        else
        {
            bool first = true;
            for (const auto& pair : *buckets[i])
            {
                if (!first) std::cout << ", ";
                std::cout << "{" << pair.GetKey() << ":" << pair.GetValue() << "}";
                first = false;
            }
        }
        std::cout << std::endl;
    }
}