#ifndef IOQUEUETWOSTACK_H
#define IOQUEUETWOSTACK_H

#include "QueueTwoStack.h" 

//! \brief Реализует логику взаимодействия с пользователем 
//! для Очереди на двух стеках.
class IOQueueTwoStack
{
public:
    //! \brief Запускает меню взаимодействия для Очереди на двух стеках.
    //! \param queue Указатель на структуру QueueTwoStack.
    static void RunQueueMenu(QueueTwoStack* queue);

private:
    //! \brief Обрабатывает ввод данных и вызывает операцию Enqueue.
    //! \param queue Указатель на структуру QueueTwoStack.
    static void HandleEnqueue(QueueTwoStack* queue);

    //! \brief Вызывает операцию Dequeue и выводит результат.
    //! \param queue Указатель на структуру QueueTwoStack.
    static void HandleDequeue(QueueTwoStack* queue);

    //! \brief Обрабатывает ввод новой емкости и вызывает операцию Resize.
    //! \param queue Указатель на структуру QueueTwoStack.
    static void HandleResize(QueueTwoStack* queue);
};

#endif // IOQUEUETWOSTACK_H