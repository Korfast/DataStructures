#ifndef QUEUERING_H
#define QUEUERING_H

#include "RingBuffer.h"

//! \brief Структура очереди на кольцевом буфере.
struct QueueRing
{
private:
    //! \brief Кольцевой буфер.
    RingBuffer* _buffer = new RingBuffer();

public:
    //! \brief Создает структуру данных очереди на кольцевом буфере.
    QueueRing();

    //! \brief Освобождает память.
    ~QueueRing();

    //! \brief Очищает очередь.
    void ClearQueue();

    //! \brief Добавляет элемент в очередь.
    //! \param data Вносимые данные.
    void Enqueue(int data);

    //! \brief Достает элемент из очереди.
    //! \return Элемент из очереди.
    int Dequeue();

    //! \brief Изменяет размер внутреннего кольцевого буфера. (Требование задания)
    //! \param newCapacity Новая емкость буфера.
    void Resize(int newCapacity);
};

#endif // QUEUERING_HNG_H