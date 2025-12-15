#include "../Header Files/IOStack.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../Header Files/io_utils.h"

// --- Приватные вспомогательные функции для IO ---

//! \brief Выводит меню стека.
static void DisplayStackMenu() {
    std::cout << "\n=== Меню: Стек ===\n";
    std::cout << "1. Добавить элемент (Push)\n";
    std::cout << "2. Извлечь элемент (Pop)\n";
    std::cout << "3. Очистить стек (Clear)\n";
    std::cout << "4. Назад в Главное меню\n";
    std::cout << "Ваш выбор: ";
}


// --- Реализация методов IOStack ---

//! \brief Обрабатывает ввод данных и вызывает операцию Push.
//! \param stack Указатель на структуру Стек.
void IOStack::HandlePush(Stack* stack)
{
    //! \brief Запрашивает у пользователя данные и добавляет их в стек.
    int data;
    std::cout << "Введите целое число для добавления (Push): ";
    if (!(std::cin >> data))
    {
        std::cout << "Ошибка ввода! Пожалуйста, введите целое число.\n";
        ClearInputBuffer();
        return;
    }

    try
    {
        stack->Push(data);
        std::cout << "Успешно: Элемент " << data << " добавлен в стек.\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при Push: " << e.what() << "\n";
    }
}

//! \brief Вызывает операцию Pop и выводит результат.
//! \param stack Указатель на структуру Стек.
void IOStack::HandlePop(Stack* stack)
{
    //! \brief Извлекает элемент из стека и выводит его значение.
    try
    {
        int data = stack->Pop();
        std::cout << "Извлечено (Pop): " << data << ".\n";
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при Pop: " << e.what() << "\n";
    }
}

//! \brief Вызывает операцию ClearStack и уведомляет пользователя.
//! \param stack Указатель на структуру Стек.
void IOStack::HandleClear(Stack* stack)
{
    //! \brief Очищает стек.
    stack->ClearStack();
    std::cout << "Стек успешно очищен.\n";
}

//! \brief Запускает меню взаимодействия для Стека.
//! \param stack Указатель на структуру Стек.
void IOStack::RunStackMenu(Stack* stack)
{
    //! \brief Главный цикл меню для АСД Стек.
    int choice = 0;
    do
    {
        DisplayStackMenu();
        if (!(std::cin >> choice))
        {
            std::cout << "Неверный ввод. Пожалуйста, введите число (1-4).\n";
            ClearInputBuffer();
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1: HandlePush(stack); break;
        case 2: HandlePop(stack); break;
        case 3: HandleClear(stack); break;
        case 4: std::cout << "Возврат в главное меню...\n"; break;
        default: std::cout << "Неизвестный выбор. Пожалуйста, попробуйте снова.\n"; break;
        }
    } while (choice != 4);
}