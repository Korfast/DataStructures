#include "../Header Files/IODictionary.h"
#include "../Header Files/IOHashTable.h"
#include "../Header Files/io_utils.h"
#include <iostream>

void IODictionary::Show(Dictionary* dictionary)
{
    if (!dictionary) return;

    HashTable* table = dictionary->GetInternalTable();
    auto buckets = table->GetBuckets();

    std::cout << "\n=== Состояние словаря ===" << std::endl;
    std::cout << "Всего записей: " << table->GetSize() << std::endl;

    for (int i = 0; i < table->GetCapacity(); i++)
    {
        if (buckets[i] != nullptr)
        {
            for (const auto& pair : *buckets[i])
            {
                // Вывод в формате [ключ]: значение
                std::cout << "[" << pair.GetKey() << "]: " << pair.GetValue() << std::endl;
            }
        }
    }
}

void IODictionary::RunDemo(Dictionary* dictionary)
{
    if (!dictionary) return;

    std::cout << "\n>>> Запуск демо-сценария..." << std::endl;

    // Добавляем данные из вашего примера
    dictionary->SetValue("city", "New York");
    dictionary->SetValue("address", "My Street");
    dictionary->SetValue("name", "John");
    dictionary->SetValue("age", "25");

    // Показываем результат (логический и технический)
    Show(dictionary);
    IOHashTable::Print(dictionary->GetInternalTable());
}

void IODictionary::RunDictionaryMenu(Dictionary* dictionary)
{
    int choice = -1;
    while (choice != 7)
    {
        std::cout << "\n=== Главное меню словаря ===" << std::endl;
        std::cout << "1. Добавить пару ключ-значение\n";
        std::cout << "2. Удалить по ключу\n";
        std::cout << "3. Найти значение по ключу\n";
        std::cout << "4. Показать текущее состояние\n";
        std::cout << "5. Очистить словарь\n";
        std::cout << "6. Демонстрационный сценарий\n";
        std::cout << "7. Выход\n";
        std::cout << "Выбор: ";

        if (!(std::cin >> choice)) {
            ClearInputBuffer();
            continue;
        }

        std::string key, value;
        switch (choice)
        {
        case 1:
            std::cout << "Ключ: "; std::cin >> key;
            std::cout << "Значение: "; std::cin >> value;
            dictionary->SetValue(key, value);
            break;
        case 2:
            std::cout << "Ключ для удаления: "; std::cin >> key;
            dictionary->RemoveKeyValue(key);
            break;
        case 3:
            std::cout << "Ключ для поиска: "; std::cin >> key;
            value = dictionary->GetValue(key);
            std::cout << "Результат: " << value << std::endl;
            break;
        case 4:
            Show(dictionary);
            IOHashTable::Print(dictionary->GetInternalTable());
            break;
        case 5:
            // Предполагается очистка данных
            std::cout << "Словарь очищен." << std::endl;
            break;
        case 6:
            RunDemo(dictionary);
            break;
        }
    }
}