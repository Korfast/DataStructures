#ifndef IOQUEUERING_H
#define IOQUEUERING_H

#include "QueueRing.h" 

//! \brief Реализует логику взаимодействия с пользователем 
//! для Очереди на кольцевом буфере.
class IOQueueRing
{
public:
    //! \brief Запускает меню взаимодействия для Очереди на кольцевом буфере.
    //! \param queue Указатель на структуру QueueRing.
    static void RunQueueMenu(QueueRing* queue);

private:
    //! \brief Обрабатывает ввод данных и вызывает операцию Enqueue.
    //! \param queue Указатель на структуру QueueRing.
    static void HandleEnqueue(QueueRing* queue);

    //! \brief Вызывает операцию Dequeue и выводит результат.
    //! \param queue Указатель на структуру QueueRing.
    static void HandleDequeue(QueueRing* queue);

    //! \brief Обрабатывает ввод новой емкости и вызывает операцию Resize.
    //! \param queue Указатель на структуру QueueRing.
    static void HandleResize(QueueRing* queue);
};

#endif // IOQUEUERING_H