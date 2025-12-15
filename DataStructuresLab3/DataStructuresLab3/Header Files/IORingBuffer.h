#ifndef IORINGBUFFER_H
#define IORINGBUFFER_H

#include "RingBuffer.h" 

//! \brief Реализует логику взаимодействия с пользователем 
//! для Кольцевого буфера.
class IORingBuffer
{
public:
    //! \brief Запускает меню взаимодействия для Кольцевого буфера.
    //! \param buffer Указатель на структуру RingBuffer.
    static void RunBufferMenu(RingBuffer* buffer);

private:
    //! \brief Обрабатывает ввод данных и вызывает операцию AddElement (Push).
    //! \param buffer Указатель на структуру RingBuffer.
    static void HandleAddElement(RingBuffer* buffer);

    //! \brief Вызывает операцию GetElement (Pop) и выводит результат.
    //! \param buffer Указатель на структуру RingBuffer.
    static void HandleGetElement(RingBuffer* buffer);

    //! \brief Вызывает функцию GetFreeSpace и выводит результат.
    //! \param buffer Указатель на структуру RingBuffer.
    static void HandleFreeSpace(RingBuffer* buffer);

    //! \brief Вызывает функцию GetSize и выводит результат (занятое место).
    //! \param buffer Указатель на структуру RingBuffer.
    static void HandleOccupiedSpace(RingBuffer* buffer);

    //! \brief Обрабатывает ввод новой емкости и вызывает операцию Resize. 
    //! \param buffer Указатель на структуру RingBuffer.
    static void HandleResize(RingBuffer* buffer);
};

#endif // IORINGBUFFER_H