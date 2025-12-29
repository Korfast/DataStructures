#include "../Header Files/IODictionary.h"
#include "../Header Files/IOHashTable.h"
#include <iostream>

void IODictionary::Show(Dictionary* dictionary)
{
    if (!dictionary) return;

    HashTable* table = dictionary->GetInternalTable();
    auto buckets = table->GetBuckets();

    std::cout << "\n=== Содержимое Словаря ===" << std::endl;
    bool isEmpty = true;
    for (int i = 0; i < table->GetCapacity(); i++)
    {
        if (buckets[i] != nullptr)
        {
            for (const auto& pair : *buckets[i])
            {
                std::cout << "Ключ: " << pair.GetKey() << " | Значение: " << pair.GetValue() << std::endl;
                isEmpty = false;
            }
        }
    }
    if (isEmpty) std::cout << "Словарь пуст." << std::endl;
}

void IODictionary::RunDemo(Dictionary* dictionary)
{
    std::cout << "\n>>> Запуск демо-сценария..." << std::endl;
    dictionary->SetValue("Table", "Стол");
    dictionary->SetValue("Chair", "Стул");
    dictionary->SetValue("Apple", "Яблоко");

    Show(dictionary);
    IOHashTable::Print(dictionary->GetInternalTable());
}