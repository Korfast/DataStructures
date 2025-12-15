#include "../Header Files/RingBuffer.h"
#include <stdexcept>
#include <iostream>
#include <cstring> // для memcpy

//! \brief Проверяет, пуст ли буфер.
bool RingBuffer::IsEmpty() const 
{
    return _size == 0;
}

//! \brief Проверяет, заполнен ли буфер.
bool RingBuffer::IsFull() const 
{
    return _size == _capacity;
}

// Конструкторы и Деструктор

RingBuffer::RingBuffer() :
    _capacity(10),
    _tailIndex(-1),
    _headIndex(-1),
    _size(0)
{
    _array = new int[_capacity];
}

RingBuffer::RingBuffer(int cap) :
    _capacity(cap),
    _tailIndex(-1),
    _headIndex(-1),
    _size(0)
{
    if (_capacity <= 0) 
    {
        throw std::invalid_argument("Ошибка: Емкость должна быть положительной.");
    }
    _array = new int[_capacity];
}

RingBuffer::~RingBuffer() 
{
    delete[] _array;
}

// Операционные методы

void RingBuffer::AddElement(int data)
{
    // 1. Проверка на необходимость увеличения размера
    if (IsFull()) 
    { 
        std::cout << "Буфер заполнен. Выполняется автоматическое увеличение размера (Resize()).\n";
        Resize();
    }

    // 2. Логика добавления
    if (_headIndex == -1) 
    {
        _headIndex = 0;
    }

    _tailIndex = (_tailIndex + 1) % _capacity;

    _array[_tailIndex] = data;
    _size++;
}

int RingBuffer::GetElement() 
{
    if (IsEmpty()) 
    { 
        throw std::out_of_range("Ошибка: Буфер пуст.");
    }

    int val = _array[_headIndex];

    _headIndex = (_headIndex + 1) % _capacity;
    _size--;

    if (_size == 0) {

        _headIndex = -1;
        _tailIndex = -1;
    }

    return val;
}

void RingBuffer::Resize() 
{
    int newCapacity = _capacity * 2;
    if (newCapacity < 1) newCapacity = 1;

    int* newArray = new int[newCapacity];

    for (int i = 0; i < _size; ++i) 
    {
        newArray[i] = _array[(_headIndex + i) % _capacity];
    }

    delete[] _array;

    _array = newArray;
    _capacity = newCapacity;
    _headIndex = 0;
    _tailIndex = _size - 1;
    if (_size == 0) 
    {
        _tailIndex = -1;
    }
}

void RingBuffer::ClearRingBuf() 
{
    _headIndex = -1;
    _tailIndex = -1;
    _size = 0;
}

// Геттеры (методы доступа)

int* RingBuffer::GetArray() 
{
    return _array;
}

// --- В RingBuffer.cpp ---
int RingBuffer::GetCapacity() const 
{
    return _capacity;
}

int RingBuffer::GetFreeSpace() const 
{ 
    return _capacity - _size;
}

int RingBuffer::GetSize() const 
{ 
    return _size;
}