#ifndef STACK_H
#define STACK_H

#include "Node.h" 

//! \brief Структура данных стек.
struct Stack
{
private:
	//! \brief Верхний элемент стека.
	Node* _top;

public:
	//! \brief Создает структуру стек.
	Stack();

	//! \brief Освобождает память.
	~Stack();

	//! \brief Возвращает верхний элемент стека.
	//! \return Верхний элемент стека.
	Node* Peek();

	//! \brief Добавляет данные в стек.
	//! \param data Данные.
	void Push(int data);

	//! \brief Достает данные из стека.
	//! \return Последние добавленные данные в стеке.
	int Pop();

	//! \brief Очищает стек.
	void ClearStack();
};

#endif // STACK_H