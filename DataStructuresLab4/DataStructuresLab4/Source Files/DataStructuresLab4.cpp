#include <iostream>
#include <clocale>
#include "../Header Files/Dictionary.h"
#include "../Header Files/IODictionary.h"
#include "../Header Files/IOHashTable.h"

void MainMenu()
{
    std::cout << "\n1. Добавить запись\n2. Удалить запись\n3. Найти значение\n";
    std::cout << "4. Показать словарь\n5. Показать структуру хеш-таблицы\n";
    std::cout << "6. Демо-сценарий\n0. Выход\nВыбор: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Dictionary* dictionary = new Dictionary();
    int choice = -1;

    while (choice != 0)
    {
        MainMenu();
        if (!(std::cin >> choice)) break;

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
            std::cout << "Результат: " << dictionary->GetValue(key) << std::endl;
            break;
        case 4:
            IODictionary::Show(dictionary);
            break;
        case 5:
            IOHashTable::Print(dictionary->GetInternalTable());
            break;
        case 6:
            IODictionary::RunDemo(dictionary);
            break;
        }
    }

    delete dictionary;
    return 0;
}