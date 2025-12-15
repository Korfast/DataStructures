#include "../Header Files/IORingBuffer.h"
#include <iostream>
#include <limits>
#include <stdexcept>
//! \brief Выводит меню кольцевого буфера.
static void DisplayBufferMenu() {
    std::cout << "\n=== Меню: Кольцевой Буфер ===\n";
    std::cout << "1. Добавить элемент (Push)\n";
    std::cout << "2. Извлечь элемент (Pop)\n";
    std::cout << "3. Свободное место (Free Space)\n";
    std::cout << "4. Занятое место (Occupied Space)\n";
    std::cout << "5. Изменить размер (Resize)\n";
    std::cout << "6. Назад в Главное меню\n";
    std::cout << "Ваш выбор: ";
}

static void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// --- Реализация методов IORingBuffer ---

//! \brief Обрабатывает ввод данных и вызывает операцию AddElement (Push).
//! \param buffer Указатель на структуру RingBuffer.
void IORingBuffer::HandleAddElement(RingBuffer* buffer)
{
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
        // ИСПРАВЛЕНИЕ: Вызываем AddElement(data)
        // В RingBuffer.h AddElement не возвращает bool, а Resize() происходит внутри
        buffer->AddElement(data);
        std::cout << "Успешно: Элемент " << data << " добавлен.\n";
    }
    catch (const std::exception& e)
    {
        // Здесь ловим только критические ошибки (например, проблемы с памятью при Resize), 
        // а не "Буфер полон", так как Resize должен предотвратить это.
        std::cerr << "Критическая ошибка при добавлении: " << e.what() << "\n";
    }
}

//! \brief Вызывает операцию GetElement (Pop) и выводит результат.
//! \param buffer Указатель на структуру RingBuffer.
void IORingBuffer::HandleGetElement(RingBuffer* buffer)
{
    try
    {
        // ИСПРАВЛЕНИЕ: Вызываем GetElement()
        int data = buffer->GetElement();
        std::cout << "Извлечено (Pop): " << data << ".\n";
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критическая ошибка при извлечении: " << e.what() << "\n";
    }
}

//! \brief Вызывает функцию GetFreeSpace и выводит результат.
//! \param buffer Указатель на структуру RingBuffer.
void IORingBuffer::HandleFreeSpace(RingBuffer* buffer)
{
    // ИСПРАВЛЕНИЕ: Вызываем GetFreeSpace() и GetCapacity()
    int freeSpace = buffer->GetFreeSpace();
    std::cout << "Свободное место: " << freeSpace << " (из " << buffer->GetCapacity() << ").\n";
}

//! \brief Вызывает функцию GetSize и выводит результат (занятое место).
//! \param buffer Указатель на структуру RingBuffer.
void IORingBuffer::HandleOccupiedSpace(RingBuffer* buffer)
{
    // ИСПРАВЛЕНИЕ: Вызываем GetSize() и GetCapacity()
    std::cout << "Занятое место: " << buffer->GetSize() << " (из " << buffer->GetCapacity() << ").\n";
}

//! \brief Обрабатывает ввод и вызывает операцию Resize.
//! \param buffer Указатель на структуру RingBuffer.
void IORingBuffer::HandleResize(RingBuffer* buffer)
{
    //! \brief Вызывает RingBuffer::Resize(), которое автоматически удваивает размер.

    // В вашем RingBuffer.h Resize() не принимает аргументов, поэтому не запрашиваем новую емкость.
    std::cout << "Выполняется автоматическое увеличение размера буфера...\n";

    try
    {
        // ИСПРАВЛЕНИЕ: Вызываем Resize() БЕЗ АРГУМЕНТОВ
        buffer->Resize();
        // Новая емкость берется из класса после вызова Resize()
        std::cout << "Успешно: Размер буфера увеличен до " << buffer->GetCapacity() << ".\n";
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

//! \brief Запускает меню взаимодействия для Кольцевого буфера.
//! \param buffer Указатель на структуру RingBuffer.
void IORingBuffer::RunBufferMenu(RingBuffer* buffer)
{
    int choice = 0;
    do
    {
        DisplayBufferMenu();
        if (!(std::cin >> choice))
        {
            std::cout << "Неверный ввод. Пожалуйста, введите число (1-6).\n";
            ClearInputBuffer();
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1: HandleAddElement(buffer); break;
        case 2: HandleGetElement(buffer); break;
        case 3: HandleFreeSpace(buffer); break;
        case 4: HandleOccupiedSpace(buffer); break;
        case 5: HandleResize(buffer); break;
        case 6: std::cout << "Возврат в главное меню...\n"; break;
        default: std::cout << "Неизвестный выбор. Пожалуйста, попробуйте снова.\n"; break;
        }
    } while (choice != 6);
}