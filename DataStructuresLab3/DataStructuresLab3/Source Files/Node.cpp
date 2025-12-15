#include "../Header Files/Node.h"

// Включаем iostream для демонстрационных или отладочных целей, хотя для основной логики он не требуется
// #include <iostream> 

//! \brief Создает структуру узла.
//! \param data Данные узла.
Node::Node(int data) : _data(data), _next(nullptr)
{
    //! \brief Инициализирует узел с данными и устанавливает указатель на следующий узел в nullptr.
}

//! \brief Освобождает память.
Node::~Node()
{
    //! \brief Деструктор. 
    // В деструкторе узла не требуется рекурсивная очистка, так как это задача 
    // управляющей структуры данных (например, Stack::ClearStack).
}

//! \brief Возвращает данные. 
//! \return Данные. 
int Node::GetData()
{
    //! \brief Возвращает значение данных, хранящихся в узле.
    return _data;
}

//! \brief Устанавливает данные 
//! \param data Данные. 
void Node::SetData(int data)
{
    //! \brief Изменяет значение данных узла.
    _data = data;
}

//! \brief Возвращает следующий узел.
//! \return Следующий узел.
Node* Node::GetNext()
{
    //! \brief Возвращает указатель на следующий узел в списке.
    return _next;
}

//! \brief Устанавливает следующий узел.
//! \param node Следующий узел.
void Node::SetNext(Node* node)
{
    //! \brief Устанавливает указатель на следующий узел.
    _next = node;
}