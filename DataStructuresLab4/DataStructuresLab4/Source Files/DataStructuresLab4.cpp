#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <clocale>
#include "../Header Files/Dictionary.h"

//! \brief Выводит текущее состояние Словаря и Хеш-таблицы.
//! \param dictionary Указатель на объект словаря.
void DisplayState(Dictionary* dictionary)
{
    if (!dictionary)
    {
        return;
    }

    HashTable* table = dictionary->GetInternalTable();
    auto buckets = table->GetBuckets();

    std::cout << "\n=== Состояние Словаря ===\n";
    std::cout << "Всего записей: " << table->GetSize() << "\n";

    for (int i = 0; i < table->GetCapacity(); i++)
    {
        if (buckets[i] != nullptr)
        {
            for (const auto& pair : *buckets[i])
            {
                std::cout << "[" << pair.GetKey() << "]: " << pair.GetValue() << "\n";
            }
        }
    }

    std::cout << "\n=== Состояние Хеш-таблицы ===\n";
    std::cout << "Вместимость: " << table->GetCapacity() << "\n";
    std::cout << "Размер: " << table->GetSize() << "\n";
    std::cout << "Коэффициент заполнения: " << (float)table->GetSize() / table->GetCapacity() << "\n";
    std::cout << "Пары ключ-значение:\n";

    for (int i = 0; i < table->GetCapacity(); i++)
    {
        std::cout << "[" << std::setw(2) << i << "]: ";
        if (buckets[i] == nullptr || buckets[i]->empty())
        {
            std::cout << "ПУСТО\n";
        }
        else
        {
            bool first = true;
            for (const auto& pair : *buckets[i])
            {
                if (!first)
                {
                    std::cout << ", ";
                }
                std::cout << "{" << pair.GetKey() << ": " << pair.GetValue() << "}";
                first = false;
            }
            std::cout << "\n";
        }
    }
}

//! \brief Сценарий демонстрации возможностей СД.
void RunDemonstration(Dictionary* dictionary)
{
    std::cout << "\n--- Запуск демонстрационных сценариев ---\n";

    std::cout << "1. Добавление нескольких пар ключ-значение...\n";
    dictionary->SetValue("город", "Москва");
    dictionary->SetValue("имя", "Иван");
    dictionary->SetValue("возраст", "25");
    DisplayState(dictionary);

    std::cout << "2. Добавление ключей для демонстрации обработки коллизий...\n";
    // В методе Пирсона ключи могут попасть в один индекс в зависимости от T-таблицы
    dictionary->SetValue("адрес", "ул. Пушкина");
    DisplayState(dictionary);

    std::cout << "3. Поиск значения для ключа 'имя': " << dictionary->GetValue("имя") << "\n";

    std::cout << "4. Попытка добавить дубликат ключа 'город'...\n";
    dictionary->SetValue("город", "Питер");

    std::cout << "5. Удаление ключа 'возраст'...\n";
    dictionary->RemoveKeyValue("возраст");
    DisplayState(dictionary);
}

int main()
{
    // Установка русской локали для консоли
    setlocale(LC_ALL, "Russian");

    Dictionary* myDictionary = new Dictionary();
    int choice = 0;

    while (true)
    {
        std::cout << "\n=== Главное меню Словаря ===\n";
        std::cout << "1. Добавить пару ключ-значение\n";
        std::cout << "2. Удалить по ключу\n";
        std::cout << "3. Найти значение по ключу\n";
        std::cout << "4. Показать текущее состояние\n";
        std::cout << "5. Очистить словарь (Новый экземпляр)\n";
        std::cout << "6. Демонстрационные сценарии\n";
        std::cout << "7. Выход\n";
        std::cout << "Ваш выбор: ";

        if (!(std::cin >> choice))
        {
            break;
        }

        std::string key, value;
        switch (choice)
        {
        case 1:
            std::cout << "Введите ключ: "; std::cin >> key;
            std::cout << "Введите значение: "; std::cin >> value;
            myDictionary->SetValue(key, value);
            DisplayState(myDictionary);
            break;
        case 2:
            std::cout << "Введите ключ для удаления: "; std::cin >> key;
            myDictionary->RemoveKeyValue(key);
            DisplayState(myDictionary);
            break;
        case 3:
            std::cout << "Введите ключ для поиска: "; std::cin >> key;
            std::cout << "Значение: " << myDictionary->GetValue(key) << "\n";
            break;
        case 4:
            DisplayState(myDictionary);
            break;
        case 5:
            delete myDictionary;
            myDictionary = new Dictionary();
            std::cout << "Словарь очищен.\n";
            break;
        case 6:
            RunDemonstration(myDictionary);
            break;
        case 7:
            delete myDictionary;
            return 0;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    delete myDictionary;
    return 0;
}