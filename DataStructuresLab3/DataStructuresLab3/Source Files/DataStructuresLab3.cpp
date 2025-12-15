#include "../Header Files/Stack.h"
#include "../Header Files/RingBuffer.h"
#include "../Header Files/QueueRing.h"
#include "../Header Files/IOStack.h"
#include "../Header Files/IORingBuffer.h"
#include "../Header Files/IOQueueRing.h"
#include "../Header Files/IOQueueTwoStack.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include "../Header Files/io_utils.h"


//! \brief Выводит главное меню.
static void DisplayMainMenu() {
    std::cout << "\n=== Главное Меню  ===\n";
    std::cout << "1. Стек (Stack)\n";
    std::cout << "2. Кольцевой Буфер (Ring Buffer)\n";
    std::cout << "3. Очередь (Circular Buffer)\n";
    std::cout << "4. Очередь (Two Stacks)\n";
    std::cout << "5. Выход";
    std::cout << "Ваш выбор: ";
}

// --- ГЛАВНАЯ ФУНКЦИЯ МЕНЮ ---

/**
 * @brief Основная функция для запуска программы и управления главным меню.
 */
static void RunDataStructuresLab3() {
    // 1. Создание экземпляров структур данных, с которыми будут работать IO-классы
    Stack stack;
    RingBuffer ringBuffer;
    QueueRing queueRing;
    QueueTwoStack queueTwoStack;

    int mainMenuChoice = 0;

    // Главный цикл программы
    do {
        DisplayMainMenu();

        if (!(std::cin >> mainMenuChoice)) {
            std::cout << "Неверный ввод. Пожалуйста, введите число (1-5).\n";
            ClearInputBuffer();
            mainMenuChoice = 0;
            continue;
        }

        ClearInputBuffer(); // Очистка после успешного ввода числа (для стабильности)

        switch (mainMenuChoice) {
        case 1:
            // Вызов IO-класса для управления меню Стека
            IOStack::RunStackMenu(&stack);
            break;
        case 2:
            // Вызов IO-класса для управления меню Кольцевого Буфера
            IORingBuffer::RunBufferMenu(&ringBuffer);
            break;
        case 3:
            // Вызов IO-класса для управления меню Очереди (на Кольцевом Буфере)
            IOQueueRing::RunQueueMenu(&queueRing);
            break;
        case 4:
            // Вызов IO-класса для управления меню Очереди (на Двух Стеках)
            IOQueueTwoStack::RunQueueMenu(&queueTwoStack);
            break;
        case 5:
            std::cout << "Выход из программы. До свидания!\n";
            break;
        default:
            std::cout << "Неизвестный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (mainMenuChoice != 5);
}


// --- ФУНКЦИЯ MAIN (точка входа) ---

int main() {
    setlocale(LC_ALL, "Russian");
    RunDataStructuresLab3();
    return 0;
}