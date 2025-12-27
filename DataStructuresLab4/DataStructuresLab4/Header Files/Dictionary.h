#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "HashTable.h"

//! \brief Структура данных словарь на базе хеш-таблицы.
struct Dictionary
{
private:
    //! \brief Указатель на внутреннюю хеш-таблицу.
    HashTable* _hashTable;

public:
    //! \brief Создает структуру данных словарь.
    Dictionary();

    //! \brief Освобождает память.
    ~Dictionary();

    //! \brief Устанавливает значение по указанному ключу.
    //! \return True если вставка успешна, False если ключ уже существует.
    bool SetValue(std::string key, std::string value);

    //! \brief Возвращает значение по ключу.
    std::string GetValue(std::string key);

    //! \brief Проверяет наличие ключа.
    bool HasKey(std::string key);

    //! \brief Удаляет пару по ключу.
    void RemoveKeyValue(std::string key);

    //! \brief Возвращает внутреннюю таблицу.
    HashTable* GetInternalTable() const;
};

#endif // DICTIONARY_H