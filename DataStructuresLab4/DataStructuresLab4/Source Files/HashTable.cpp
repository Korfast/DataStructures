#include "../Header Files/HashTable.h"
#include <numeric>
#include <algorithm>
#include <random>

//! \brief Конструктор по умолчанию.
HashTable::HashTable() : HashTable(16)
{
}

//! \brief Конструктор с заданной начальной вместимостью.
HashTable::HashTable(int initialCapacity)
{
    _capacity = initialCapacity;
    _size = 0;
    _buckets = new std::list<KeyValuePair>*[_capacity];
    for (int i = 0; i < _capacity; i++)
    {
        _buckets[i] = nullptr;
    }

    // Инициализация таблицы для метода Пирсона
    std::iota(std::begin(_tTable), std::end(_tTable), 0);
    std::shuffle(std::begin(_tTable), std::end(_tTable),
        std::mt19937(std::random_device()()));
}

//! \brief Деструктор.
HashTable::~HashTable()
{
    for (int i = 0; i < _capacity; i++)
    {
        if (_buckets[i] != nullptr)
        {
            delete _buckets[i];
        }
    }
    delete[] _buckets;
}

//! \brief Вычисляет хеш от ключа методом Пирсона.
int HashTable::HashFunction(std::string key)
{
    unsigned char h = 0;
    for (char c : key)
    {
        h = _tTable[h ^ static_cast<unsigned char>(c)];
    }
    return h % _capacity;
}

//! \brief Вставляет пару "ключ-значение".
bool HashTable::Insert(std::string key, std::string value)
{
    int index = HashFunction(key);
    if (_buckets[index] == nullptr)
    {
        _buckets[index] = new std::list<KeyValuePair>();
    }

    _buckets[index]->push_back(KeyValuePair(key, value));
    _size++;
    return true;
}

//! \brief Ищет значение по ключу.
bool HashTable::Find(std::string key, std::string& value)
{
    int index = HashFunction(key);
    if (_buckets[index] == nullptr) return false;

    for (const auto& pair : *_buckets[index])
    {
        if (pair.GetKey() == key)
        {
            value = pair.GetValue();
            return true;
        }
    }
    return false;
}

//! \brief Удаляет пару по ключу.
bool HashTable::Remove(std::string key)
{
    int index = HashFunction(key);
    if (_buckets[index] == nullptr) return false;

    auto& chain = *_buckets[index];
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (it->GetKey() == key)
        {
            chain.erase(it);
            _size--;
            return true;
        }
    }
    return false;
}

//! \brief Изменение размера таблицы.
bool HashTable::Resize(int newCapacity)
{
    if (newCapacity <= _size) return false;

    // Создаем новую структуру
    std::list<KeyValuePair>** newBuckets = new std::list<KeyValuePair>*[newCapacity];
    for (int i = 0; i < newCapacity; i++)
    {
        newBuckets[i] = nullptr;
    }

    int oldCapacity = _capacity;
    _capacity = newCapacity; // Временно меняем для HashFunction

    // Переносим данные
    for (int i = 0; i < oldCapacity; i++)
    {
        if (_buckets[i] != nullptr)
        {
            for (const auto& pair : *_buckets[i])
            {
                int newIndex = HashFunction(pair.GetKey());
                if (newBuckets[newIndex] == nullptr)
                {
                    newBuckets[newIndex] = new std::list<KeyValuePair>();
                }
                newBuckets[newIndex]->push_back(pair);
            }
            delete _buckets[i];
        }
    }

    delete[] _buckets;
    _buckets = newBuckets;
    return true;
}