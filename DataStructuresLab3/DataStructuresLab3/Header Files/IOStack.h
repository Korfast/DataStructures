#ifndef IOSTACK_H
#define IOSTACK_H

#include "Stack.h" 

//! \brief Реализует логику взаимодействия с пользователем для Стека.
class IOStack
{
public:
    //! \brief Запускает меню взаимодействия для Стека.
    //! \param stack Указатель на структуру Стек.
    static void RunStackMenu(Stack* stack);

private:
    //! \brief Обрабатывает ввод данных и вызывает операцию Push.
    //! \param stack Указатель на структуру Стек.
    static void HandlePush(Stack* stack);

    //! \brief Вызывает операцию Pop и выводит результат.
    //! \param stack Указатель на структуру Стек.
    static void HandlePop(Stack* stack);

    //! \brief Вызывает операцию ClearStack и уведомляет пользователя.
    //! \param stack Указатель на структуру Стек.
    static void HandleClear(Stack* stack);
};

#endif // IOSTACK_H