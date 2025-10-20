#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray
{
private:
    int _size;
    int _capacity;
    int* _array;

    void resizeArray(int newCapacity);

public:
    explicit DynamicArray(int initCapacity = 8);
    ~DynamicArray();

    void Init();
    int GetSize() const { return _size; }
    int GetCapacity() const { return _capacity; }
    int* GetArray() const { return _array; }

    void AddToEnd(int value);
    void AddToStart(int value);
    void InsertAfter(int index, int value);
    void InsertAt(int index, int value);

    void RemoveByIndex(int index);
    void RemoveByValue(int value);

    int GetElement(int index) const;

    void Sort(int variant);
    int LinearSearch(int value) const;
    int BinarySearch(int value) const;

};

#endif // DYNAMICARRAY_H