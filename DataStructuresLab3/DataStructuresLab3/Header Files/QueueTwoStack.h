#ifndef QUEUETWOSTACK_H
#define QUEUETWOSTACK_H

#include "Stack.h"

//! \brief Структура очереди на двух стеках.
struct QueueTwoStack
{
private:
    //! \brief Основной стек, в который будут добавляться элементы.
    Stack* _inStack;

    //! \brief Второстепенный стек, из которого будут возвращаться элементы.
    Stack* _outStack;

public:
    //! \brief Создает структуру данных очереди на двух стеках.
    QueueTwoStack();

    //! \brief Освобождает память.
    ~QueueTwoStack();

    //! \brief Очищает очередь.
    void ClearQueue();

    //! \brief Добавляет элемент в очередь.
    //! \param data Вносимые данные.
    void Enqueue(int data);

    //! \brief Достает элемент из очереди.
    //! \return Элемент из очереди.
    int Dequeue();

    //! \brief Изменяет размер underlying структур данных.
    //! \param newCapacity Новая емкость.
    void Resize(int newCapacity);
};

#endif // QUEUETWOSTACK_H