#include "../Header Files/IOQueueTwoStack.h"
#include <iostream>
#include <limits>
#include <stdexcept>

// --- Приватные вспомогательные функции для IO ---

//! \brief Выводит меню очереди на двух стеках.
static void DisplayQueueTwoStackMenu() {
    std::cout << "\n=== Меню: Очередь (на Двух Стеках) ===\n";
    std::cout << "1. Добавить элемент (Enqueue)\n";
    std::cout << "2. Извлечь элемент (Dequeue)\n";
    std::cout << "3. Изменить размер (Resize) - *Неприменимо*\n";
    std::cout << "4. Назад в Главное меню\n";
    std::cout << "Ваш выбор: ";
}

static void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// --- Реализация методов IOQueueTwoStack ---

//! \brief Обрабатывает ввод данных и вызывает операцию Enqueue.
//! \param queue Указатель на структуру QueueTwoStack.
void IOQueueTwoStack::HandleEnqueue(QueueTwoStack* queue)
{
    // Аналогично HandleEnqueue
    int data;
    std::cout << "Введите целое число для добавления (Enqueue): ";
    if (!(std::cin >> data))
    {
        std::cout << "Ошибка ввода! Пожалуйста, введите целое число.\n";
        ClearInputBuffer();
        return;
    }

    try
    {
        queue->Enqueue(data);
        std::cout << "Успешно: Элемент " << data << " добавлен в очередь.\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при Enqueue: " << e.what() << "\n";
    }
}

//! \brief Вызывает операцию Dequeue и выводит результат.
//! \param queue Указатель на структуру QueueTwoStack.
void IOQueueTwoStack::HandleDequeue(QueueTwoStack* queue)
{
    // Аналогично HandleDequeue
    try
    {
        int data = queue->Dequeue();
        std::cout << "Извлечено (Dequeue): " << data << ".\n";
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при Dequeue: " << e.what() << "\n";
    }
}

//! \brief Обрабатывает ввод новой емкости и вызывает операцию Resize (заглушка).
//! \param queue Указатель на структуру QueueTwoStack.
void IOQueueTwoStack::HandleResize(QueueTwoStack* queue)
{
    //! \brief Уведомляет пользователя о том, что для очереди, основанной на стеках
    // на связанном списке, изменение размера не требуется.
    std::cout << "Очередь, реализованная на стеках (на связанных списках), автоматически управляет памятью.\n";
    std::cout << "Явное изменение размера (Resize) не требуется.\n";
}

//! \brief Запускает меню взаимодействия для Очереди на двух стеках.
//! \param queue Указатель на структуру QueueTwoStack.
void IOQueueTwoStack::RunQueueMenu(QueueTwoStack* queue)
{
    //! \brief Главный цикл меню для АСД Очередь на Двух Стеках.
    int choice = 0;
    do
    {
        DisplayQueueTwoStackMenu();
        if (!(std::cin >> choice))
        {
            std::cout << "Неверный ввод. Пожалуйста, введите число (1-4).\n";
            ClearInputBuffer();
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1: HandleEnqueue(queue); break;
        case 2: HandleDequeue(queue); break;
        case 3: HandleResize(queue); break; // Вызов заглушки
        case 4: std::cout << "Возврат в главное меню...\n"; break;
        default: std::cout << "Неизвестный выбор. Пожалуйста, попробуйте снова.\n"; break;
        }
    } while (choice != 4);
}