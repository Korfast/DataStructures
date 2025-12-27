#include "../Header Files/Dictionary.h"
#include <iostream>

//! \brief Создает структуру данных словарь.
Dictionary::Dictionary()
{
    _hashTable = new HashTable();
}

//! \brief Освобождает память.
Dictionary::~Dictionary()
{
    delete _hashTable;
}

//! \brief Устанавливает значение по указанному ключу.
bool Dictionary::SetValue(std::string key, std::string value)
{
    std::string existingValue;
    // Проверка на уникальность ключа перед вставкой
    if (_hashTable->Find(key, existingValue))
    {
        std::cout << "Error: Duplicate key '" << key << "' not allowed!" << std::endl;
        return false;
    }
    return _hashTable->Insert(key, value);
}

//! \brief Возвращает значение по ключу.
std::string Dictionary::GetValue(std::string key)
{
    std::string value;
    if (_hashTable->Find(key, value))
    {
        return value;
    }
    return "Not Found";
}

//! \brief Проверяет наличие ключа.
bool Dictionary::HasKey(std::string key)
{
    std::string dummy;
    return _hashTable->Find(key, dummy);
}

//! \brief Удаляет пару.
void Dictionary::RemoveKeyValue(std::string key)
{
    _hashTable->Remove(key);
}

//! \brief Возвращает указатель на таблицу.
HashTable* Dictionary::GetInternalTable() const
{
    return _hashTable;
}