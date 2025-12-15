 #ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

//! \brief Структура динамического массива.
struct DynamicArray
{
private:
    // RSDN
    // \brief Коэффициент роста массива при необходимости расширения.
    const int GrowthFactor = 2;
    // \brief Текущий размер массива.
    int _size;
    // \brief Максимальное количество элементов, которое может вместить массив.
    int _capacity;
    // \brief Указатель на динамический массив элементов.
    int* _array;

    // \brief Увеличивает размер массива до нового емкостного размера.
    //! \param newCapacity - новый размер массива.
    void ResizeArray(int newCapacity);

public:
    //! \brief Конструктор с заданной начальной вместимостью (по умолчанию 8).
    //! \param initCapacity - начальная вместимость массива.
    explicit DynamicArray(int initCapacity = 8);
    //! \brief Деструктор.
    ~DynamicArray();

    //! \brief Инициализация массива (может быть вызвана для установки в исходное состояние).
    void Init();

    //! \brief Сдвигает элементы массива вправо начиная с startIndex.
    //! \param startIndex - индекс, с которого начинаем сдвиг.
    void ShiftRight(int startIndex);

    //! \brief Сдвигает элементы массива влево начиная с startIndex.
    //! \param startIndex - индекс, с которого начинаем сдвиг.
    void ShiftLeft(int startIndex);

    //! \brief Возвращает текущий размер массива.
    //! \return текущий размер.
    int GetSize() const { return _size; }

    //! \brief Возвращает текущую вместимость массива.
    //! \return емкость массива.
    int GetCapacity() const { return _capacity; }

    //! \brief Возвращает указатель на внутренний массив элементов.
    //! \return указатель на массив.
    int* GetArray() const { return _array; }

    //! \brief Добавляет элемент в конец массива.
    //! \param value - значение для добавления.
    void AddToEnd(int value);

    //! \brief Добавляет элемент в начало массива.
    //! \param value - значение для добавления.
    void AddToStart(int value);

    //! \brief Вставляет элемент после указанного индекса.
    //! \param index - индекс, после которого вставляем.
    //! \param value - значение для вставки.
    void InsertAfter(int index, int value);

    //! \brief Вставляет элемент на указанную позицию.
    //! \param index - индекс, на который вставляем.
    //! \param value - значение для вставки.
    void InsertAt(int index, int value);

    //! \brief Удаляет элемент по указанному индексу.
    //! \param index - индекс удаляемого элемента.
    void RemoveByIndex(int index);

    //! \brief Удаляет первый встреченный элемент со значением.
    //! \param value - значение для удаления.
    void RemoveByValue(int value);

    //! \brief Возвращает элемент по указанному индексу.
    //! \param index - индекс запрашиваемого элемента.
    //! \return значение элемента.
    int GetElement(int index) const;

    //! \brief Сортирует массив по выбранному методу.
    //! \param variant - номер варианта сортировки.
    void Sort(int variant);

    //! \brief Выполняет линейный поиск элемента.
    //! \param value - значение для поиска.
    //! \return индекс элемента, или -1 если не найден.
    int LinearSearch(int value) const;

    //! \brief Выполняет двоичный поиск элемента (для отсортированного массива).
    //! \param value - значение для поиска.
    //! \return индекс элемента, или -1 если не найден.
    int BinarySearch(int value) const;
};

#endif // DYNAMICARRAY_H