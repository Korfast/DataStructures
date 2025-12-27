#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include "KeyValuePair.h"

//! \brief Хеш-таблица с методом цепочек для разрешения коллизий.
struct HashTable
{
private:
    //! \brief Вместимость хеш-таблицы (количество корзин).
    int _capacity;

    //! \brief Текущее количество элементов в таблице.
    int _size;

    //! \brief Массив указателей на списки пар "ключ-значение" (цепочки).
    std::list<KeyValuePair>** _buckets;

    //! \brief Таблица перестановок для реализации хеширования методом Пирсона.
    unsigned char _tTable[256];

    //! \brief Вычисляет индекс в таблице на основе ключа методом Пирсона.
    //! \param key Строка-ключ.
    //! \return Индекс в массиве корзин.
    int HashFunction(std::string key);

public:
    //! \brief Конструктор по умолчанию (инициализирует таблицу размером 16).
    HashTable();

    //! \brief Конструктор с возможностью задания начального размера.
    //! \param initialCapacity Начальная вместимость таблицы.
    HashTable(int initialCapacity);

    //! \brief Деструктор. Освобождает память, выделенную под корзины и списки.
    ~HashTable();

    //! \brief Вставляет новую пару "ключ-значение". Допускает дубликаты.
    //! \param key Ключ.
    //! \param value Значение.
    //! \return True, если вставка прошла успешно.
    bool Insert(std::string key, std::string value);

    //! \brief Выполняет поиск значения по ключу.
    //! \param key Ключ для поиска.
    //! \param value [out] Переменная, в которую будет записано найденное значение.
    //! \return True, если элемент найден.
    bool Find(std::string key, std::string& value);

    //! \brief Удаляет элемент из таблицы по ключу.
    //! \param key Ключ для удаления.
    //! \return True, если элемент был найден и удален.
    bool Remove(std::string key);

    //! \brief Увеличивает вместимость таблицы и пересчитывает позиции элементов.
    //! \param newCapacity Новая вместимость.
    //! \return True в случае успешного перехеширования.
    bool Resize(int newCapacity);

    //! \brief Возвращает текущее количество элементов в хеш-таблице.
    //! \return Количество элементов.
    int GetSize() const { return _size; }

    //! \brief Возвращает текущую вместимость (размер массива корзин).
    //! \return Вместимость.
    int GetCapacity() const { return _capacity; }

    //! \brief Возвращает указатель на массив корзин для визуализации состояния.
    //! \return Указатель на массив списков.
    std::list<KeyValuePair>** GetBuckets() const { return _buckets; }
};

#endif