#include "../Header Files/QueueRing.h"
#include <stdexcept>

// Предполагается, что RingBuffer.h уже содержит объявления RingBuffer,
// а также методы AddElement, GetElement, ClearRingBuf и Resize(int).

//! \brief Создает структуру данных очереди на кольцевом буфере.
QueueRing::QueueRing()
{
    // ! \brief Конструктор. 
    // Поскольку RingBuffer* _buffer уже инициализирован через new RingBuffer()
    // в объявлении члена (в заголовочном файле), тело конструктора может быть пустым.
    // Если бы мы хотели передать емкость, мы бы использовали:
    // _buffer = new RingBuffer(capacity);
}

//! \brief Освобождает память.
QueueRing::~QueueRing()
{
    //! \brief Деструктор. 
    // Освобождает память, выделенную для кольцевого буфера.
    if (_buffer != nullptr)
    {
        delete _buffer;
        _buffer = nullptr;
    }
}

//! \brief Очищает очередь.
void QueueRing::ClearQueue()
{
    //! \brief Очищает очередь путем вызова функции очистки кольцевого буфера.
    if (_buffer != nullptr)
    {
        _buffer->ClearRingBuf();
    }
}

//! \brief Добавляет элемент в очередь.
//! \param data Вносимые данные.
void QueueRing::Enqueue(int data)
{
    //! \brief Добавляет элемент в конец очереди (FIFO).
    // Использует функцию добавления элемента в кольцевой буфер.
    if (_buffer != nullptr)
    {
        _buffer->AddElement(data);
    }
    else
    {
        // Обработка критической ошибки, если буфер не инициализирован.
        throw std::runtime_error("Ошибка: Внутренний буфер очереди не инициализирован.");
    }
}

//! \brief Достает элемент из очереди.
//! \return Элемент из очереди.
int QueueRing::Dequeue()
{
    //! \brief Достает элемент из начала очереди (FIFO).
    // Использует функцию извлечения элемента из кольцевого буфера.
    if (_buffer != nullptr)
    {
        // Предполагается, что GetElement() в RingBuffer обрабатывает случай пустого буфера.
        return _buffer->GetElement();
    }
    else
    {
        throw std::runtime_error("Ошибка: Внутренний буфер очереди не инициализирован.");
    }
}

//! \brief Изменяет размер внутреннего кольцевого буфера. (Требование задания)
//! \param newCapacity Новая емкость буфера.
void QueueRing::Resize(int newCapacity)
{
    //! \brief Изменяет размер underlying RingBuffer.
    // Вызывает соответствующую функцию изменения размера кольцевого буфера.
    if (_buffer != nullptr)
    {
        // Предполагается, что в RingBuffer реализована функция Resize(int newCapacity),
        // которая корректно обрабатывает перенос данных.
        _buffer->Resize(newCapacity);
    }
    else
    {
        throw std::runtime_error("Ошибка: Внутренний буфер очереди не инициализирован.");
    }
}