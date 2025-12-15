#include "../Header Files/QueueTwoStack.h"
#include "../Header Files/Stack.h"
#include <stdexcept>

// --- Вспомогательная функция (для внутренней проверки пустоты стека) ---
//! \brief Проверяет, пуст ли стек, используя его метод Peek().
//! \param stack Указатель на проверяемый стек.
//! \return true, если стек пуст, иначе false.
static bool StackIsEmpty(Stack* stack)
{
    // Предполагается, что Stack::Peek() возвращает nullptr, если стек пуст.
    return stack->Peek() == nullptr;
}

//! \brief Создает структуру данных очереди на двух стеках.
QueueTwoStack::QueueTwoStack()
{
    //! \brief Конструктор. 
    // Динамически выделяем память для двух стеков.
    _inStack = new Stack();
    _outStack = new Stack();
}

//! \brief Освобождает память.
QueueTwoStack::~QueueTwoStack()
{
    //! \brief Деструктор. 
    // Освобождаем память, выделенную для двух стеков.
    if (_inStack != nullptr)
    {
        delete _inStack;
        _inStack = nullptr;
    }
    if (_outStack != nullptr)
    {
        delete _outStack;
        _outStack = nullptr;
    }
}

//! \brief Очищает очередь.
void QueueTwoStack::ClearQueue()
{
    //! \brief Очищает оба стека, тем самым полностью очищая очередь.
    if (_inStack != nullptr)
    {
        _inStack->ClearStack();
    }
    if (_outStack != nullptr)
    {
        _outStack->ClearStack();
    }
}

//! \brief Добавляет элемент в очередь.
//! \param data Вносимые данные.
void QueueTwoStack::Enqueue(int data)
{
    //! \brief Добавляет элемент в основной стек (_inStack).
    if (_inStack != nullptr)
    {
        _inStack->Push(data);
    }
    else
    {
        throw std::runtime_error("Ошибка: Стек для ввода не инициализирован.");
    }
}

//! \brief Достает элемент из очереди.
//! \return Элемент из очереди.
int QueueTwoStack::Dequeue()
{
    //! \brief Извлекает элемент из очереди, реализуя принцип FIFO на двух стеках.

    // 1. Проверяем, пуст ли стек вывода (_outStack).
    if (StackIsEmpty(_outStack))
    {
        // Если _outStack пуст, проверяем _inStack.
        if (StackIsEmpty(_inStack))
        {
            // Если оба стека пусты, очередь пуста.
            throw std::out_of_range("Ошибка: Очередь пуста (Underflow).");
        }

        //! \brief Перекладываем все элементы из _inStack в _outStack.
        // Это действие инвертирует порядок элементов, подготавливая их к FIFO-извлечению.
        while (!StackIsEmpty(_inStack))
        {
            int data = _inStack->Pop();
            _outStack->Push(data);
        }
    }

    // 2. Извлекаем элемент из _outStack.
    // Проверка на пустоту _outStack гарантирует, что мы не пытаемся Pop() из пустого стека.
    // (Если _outStack был пуст, но _inStack был не пуст, мы только что его заполнили)
    return _outStack->Pop();
}

/*
//! \brief Изменяет размер underlying структур данных.
//! \param newCapacity Новая емкость.
void QueueTwoStack::Resize(int newCapacity)
{
    //! \brief Изменяет размер underlying структур данных.
    // Вызывает метод Resize() для обоих стеков. 
    // Это актуально, если Stack реализован на массиве.

    if (_inStack != nullptr)
    {
        // Предполагается, что Stack имеет метод Resize(int).
        _inStack->Resize(newCapacity);
    }
    if (_outStack != nullptr)
    {
        // Предполагается, что Stack имеет метод Resize(int).
        _outStack->Resize(newCapacity);
    }
}
*/