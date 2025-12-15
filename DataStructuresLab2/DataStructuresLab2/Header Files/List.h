#ifndef LIST_H
#define LIST_H

#include "Node.h" 

//! \brief Структура двусвязного списка. 
struct List
{
private:
    //! \brief Поле указателя начального узла. 
    Node* _head;

    //! \brief Поле указателя конечного узла. 
    Node* _tail;

    //! \brief Поле количества элементов в списке. 
    int _size;

public:
    //! \brief Конструктор по умолчанию.
    List();

    //! \brief Деструктор.
    ~List();

    //! \brief Возвращает указатель на начальный узел. 
    //! \return Указатель на начальный узел. 
    Node* GetHead();

    //! \brief Возвращает указатель на конечный узел. 
    //! \return Указатель на конечный узел. 
    Node* GetTail();

    //! \brief Возвращает текущее количество узлов в списке.
    //! \return Количество элементов.
    int GetSize();

    //! \brief Возвращает узел по указанному индексу. 
    //! \param index Индекс, по которому нужно получить узел. 
    //! \return Узел. 
    Node* GetNodeByIndex(int index);

    //! \brief Добавляет новый узел в список по индексу. 
    //! \param node Указатель на новый узел. 
    //! \param index Индекс, по которому нужно установить новый узел. 
    //! \return Возвращает true, если удалось добавить элемент, или false, если индекс некорректен.
    bool AddNode(Node* node, int index);

    //! \brief Удаляет узел по индексу. 
    //! \param index Индекс узла. 
    //! \return Возвращает true, если удалось удалить элемент, или false, если индекс некорректен.
    bool RemoveNodeByIndex(int index);

    //! \brief Удаляет первый узел по значению внутри узла. 
    //! \param value Значение внутри узла. 
    void RemoveNodeByValue(int value);

    //! \brief Сортирует двусвязный список (пузырьковая сортировка). 
    void Sort();

    //! \brief Находит узел по указанному значению. 
    //! \param value Значение, по которому ищется узел. 
    //! \return Найденный узел или nullptr. 
    Node* FindNodeByValue(int value);

    //! \brief Очищает список от всех элементов. 
    void Clean();
};

#endif // LIST_H