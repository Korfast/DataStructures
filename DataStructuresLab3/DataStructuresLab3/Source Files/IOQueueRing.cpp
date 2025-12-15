#include "../Header Files/IOQueueRing.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../Header Files/io_utils.h"

// --- Приватные вспомогательные функции для IO ---

//! \brief Выводит меню очереди на кольцевом буфере.
static void DisplayQueueRingMenu() {
    std::cout << "\n=== Меню: Очередь (на Кольцевом Буфере) ===\n";
    std::cout << "1. Добавить элемент (Enqueue)\n";
    std::cout << "2. Извлечь элемент (Dequeue)\n";
    std::cout << "3. Изменить размер (Resize)\n";
    std::cout << "4. Назад в Главное меню\n";
    std::cout << "Ваш выбор: ";
}

// --- Реализация методов IOQueueRing ---

//! \brief Обрабатывает ввод данных и вызывает операцию Enqueue.
//! \param queue Указатель на структуру QueueRing.
void IOQueueRing::HandleEnqueue(QueueRing* queue)
{
    // Аналогично HandlePush
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
    catch (const std::out_of_range& e)
    {
        std::cout << "Ошибка: Очередь полна. " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при Enqueue: " << e.what() << "\n";
    }
}

//! \brief Вызывает операцию Dequeue и выводит результат.
//! \param queue Указатель на структуру QueueRing.
void IOQueueRing::HandleDequeue(QueueRing* queue)
{
    // Аналогично HandlePop
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

//! \brief Обрабатывает ввод новой емкости и вызывает операцию Resize.
//! \param queue Указатель на структуру QueueRing.
void IOQueueRing::HandleResize(QueueRing* queue)
{
    //! \brief Запрашивает новую емкость и вызывает QueueRing::Resize() для underlying RingBuffer.
    int newCapacity;
    std::cout << "Введите новую емкость очереди: ";
    if (!(std::cin >> newCapacity))
    {
        std::cout << "Ошибка ввода! Пожалуйста, введите целое число.\n";
        ClearInputBuffer();
        return;
    }

    try
    {
        queue->Resize(newCapacity);
        std::cout << "Успешно: Размер очереди изменен на " << newCapacity << ".\n";
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Ошибка изменения размера: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при Resize: " << e.what() << "\n";
    }
}

//! \brief Запускает меню взаимодействия для Очереди на кольцевом буфере.
//! \param queue Указатель на структуру QueueRing.
void IOQueueRing::RunQueueMenu(QueueRing* queue)
{
    //! \brief Главный цикл меню для АСД Очередь на Кольцевом Буфере.
    int choice = 0;
    do
    {
        DisplayQueueRingMenu();
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
        case 3: HandleResize(queue); break;
        case 4: std::cout << "Возврат в главное меню...\n"; break;
        default: std::cout << "Неизвестный выбор. Пожалуйста, попробуйте снова.\n"; break;
        }
    } while (choice != 4);
}