#include "DynamicArray.h"

// Конструктор
DynamicArray::DynamicArray(int initCapacity) : _size(0), _capacity(initCapacity)
{
    _array = new int[_capacity];
}

// Деструктор
DynamicArray::~DynamicArray()
{
    delete[] _array;
}

// Инициализация массива (заполнение нулями)
void DynamicArray::Init()
{
    _size = 0;
    for (int i = 0; i < _capacity; ++i) {
        _array[i] = 0;
    }
}

// Приватный метод изменения размера массива
void DynamicArray::resizeArray(int newCapacity)
{
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _size; ++i) {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

// Добавление элемента в конец
void DynamicArray::AddToEnd(int value)
{
    if (_size >= _capacity) {
        resizeArray(_capacity * 2);
    }
    _array[_size++] = value;
}

// Добавление элемента в начало
void DynamicArray::AddToStart(int value)
{
    if (_size >= _capacity) {
        resizeArray(_capacity * 2);
    }
    for (int i = _size; i > 0; --i) {
        _array[i] = _array[i - 1];
    }
    _array[0] = value;
    ++_size;
}

// Вставка после определенного индекса
void DynamicArray::InsertAfter(int index, int value)
{
    if (index < 0 || index >= _size) return;

    if (_size >= _capacity) {
        resizeArray(_capacity * 2);
    }
    for (int i = _size; i > index + 1; --i) {
        _array[i] = _array[i - 1];
    }
    _array[index + 1] = value;
    ++_size;
}

// Вставка по индексу
void DynamicArray::InsertAt(int index, int value)
{
    if (index < 0 || index > _size) return;

    if (_size >= _capacity) {
        resizeArray(_capacity * 2);
    }
    for (int i = _size; i > index; --i) {
        _array[i] = _array[i - 1];
    }
    _array[index] = value;
    ++_size;
}

// Удаление по индексу
void DynamicArray::RemoveByIndex(int index)
{
    if (index < 0 || index >= _size) return;

    for (int i = index; i < _size - 1; ++i) {
        _array[i] = _array[i + 1];
    }
    --_size;

    if (_capacity > 8 && _size < _capacity / 4) {
        resizeArray(_capacity / 2);
    }
}

// Удаление по значению
void DynamicArray::RemoveByValue(int value)
{
    for (int i = 0; i < _size; ++i) {
        if (_array[i] == value) {
            RemoveByIndex(i);
            --i; // чтобы проверить новый сдвинутый элемент
        }
    }
}

// Получение элемента по индексу с проверкой
int DynamicArray::GetElement(int index) const
{
    if (index < 0 || index >= _size) {
        std::cerr << "Index out of range\n";
        return 0; // или бросить исключение
    }
    return _array[index];
}

// Сортировка по варианту
void DynamicArray::Sort(int variant)
{
    switch (variant) {
    case 1: // пузырьковая
        for (int i = 0; i < _size - 1; ++i)
            for (int j = 0; j < _size - i - 1; ++j)
                if (_array[j] > _array[j + 1])
                    std::swap(_array[j], _array[j + 1]);
        break;
    case 2: // выбором
        for (int i = 0; i < _size - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < _size; ++j)
                if (_array[j] < _array[minIdx])
                    minIdx = j;
            std::swap(_array[i], _array[minIdx]);
        }
        break;
    case 3: // вставками
        for (int i = 1; i < _size; ++i) {
            int key = _array[i];
            int j = i - 1;
            while (j >= 0 && _array[j] > key) {
                _array[j + 1] = _array[j];
                --j;
            }
            _array[j + 1] = key;
        }
        break;
    default:
        break;
    }
}

// Линейный поиск
int DynamicArray::LinearSearch(int value) const
{
    for (int i = 0; i < _size; ++i) {
        if (_array[i] == value)
            return i;
    }
    return -1;
}

// Бинарный поиск (массив должен быть отсортирован)
int DynamicArray::BinarySearch(int value) const
{
    int left = 0, right = _size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (_array[mid] == value)
            return mid;
        else if (_array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}