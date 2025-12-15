#include "../Header Files/Stack.h"
#include "../Header Files/Node.h"
#include <stdexcept>
#include <iostream>

// --- Основные функции из Stack.h ---

//! \brief Создает структуру стек.
Stack::Stack() : _top(nullptr)
{
    // Инициализация вершины стека.
}

//! \brief Освобождает память.
Stack::~Stack()
{
    //! \brief Деструктор. 
    // Освобождает всю память, занятую узлами, через ClearStack.
    ClearStack();
}

//! \brief Возвращает верхний элемент стека.
//! \return Верхний элемент стека.
Node* Stack::Peek()
{
    //! \brief Возвращает указатель на верхний узел.
    return _top;
}

//! \brief Добавляет данные в стек.
//! \param data Данные.
void Stack::Push(int data)
{
    //! \brief Создает новый узел и делает его вершиной стека.
    // 1. Создаем новый узел.
    Node* newNode = new Node(data);

    // 2. Новый узел указывает на текущую вершину (Peek()).
    newNode->SetNext(_top);

    // 3. Обновляем вершину.
    _top = newNode;
}

//! \brief Достает данные из стека.
//! \return Последние добавленные данные в стеке.
int Stack::Pop()
{
    //! \brief Извлекает верхний элемент (LIFO) и освобождает память.

    // 1. Проверяем, пуст ли стек, используя Peek().
    if (Peek() == nullptr)
    {
        throw std::out_of_range("Ошибка: Стек пуст (Underflow)");
    }

    // 2. Получаем верхний узел.
    Node* temp = Peek();

    // 3. Получаем данные с помощью публичного геттера Node::GetData().
    int val = temp->GetData();

    // 4. Перемещаем вершину на следующий узел с помощью Node::GetNext().
    _top = temp->GetNext();

    // 5. Освобождаем память удаленного узла.
    delete temp;

    return val;
}

//! \brief Очищает стек.
void Stack::ClearStack()
{
    //! \brief Удаляет все узлы стека в цикле.
    while (_top != nullptr)
    {
        Node* oldTop = _top;

        // Переходим к следующему узлу перед удалением текущего
        _top = oldTop->GetNext();

        delete oldTop;
    }
}