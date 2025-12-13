#include <iostream>
#include "../Header Files/List.h"

using namespace std;

List::List() : _head(nullptr), _tail(nullptr), _size(0)
{
}

List::~List()
{
    Clean();
}

Node* List::GetHead()
{
    return _head;
}

Node* List::GetTail()
{
    return _tail;
}

int List::GetSize()
{
    return _size;
}

Node* List::GetNodeByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        return nullptr;
    }

    // Оптимизация: ищем с конца, если индекс во второй половине списка
    Node* current;
    if (index < _size / 2)
    {
        current = _head;
        for (int i = 0; i < index; i++)
        {
            current = current->GetNextNode();
        }
    }
    else
    {
        current = _tail;
        for (int i = _size - 1; i > index; i--)
        {
            current = current->GetPreviousNode();
        }
    }
    return current;
}

bool List::AddNode(Node* node, int index)
{
    if (index < 0 || index > _size)
    {
        return false;
    }

    // Случай 1: Добавление в пустой список или в начало
    if (index == 0)
    {
        node->SetNextNode(_head);
        node->SetPreviousNode(nullptr);

        if (_head != nullptr)
        {
            _head->SetPreviousNode(node);
        }
        _head = node;

        if (_tail == nullptr)
        {
            _tail = node;
        }
    }
    // Случай 2: Добавление в конец
    else if (index == _size)
    {
        node->SetNextNode(nullptr);
        node->SetPreviousNode(_tail);

        if (_tail != nullptr)
        {
            _tail->SetNextNode(node);
        }
        _tail = node;
    }
    // Случай 3: Вставка в середину
    else
    {
        // Узел, который сейчас стоит на этом месте
        Node* current = GetNodeByIndex(index); 
        Node* prev = current->GetPreviousNode();

        prev->SetNextNode(node);
        node->SetPreviousNode(prev);

        node->SetNextNode(current);
        current->SetPreviousNode(node);
    }

    _size++;
    return true;
}

bool List::RemoveNodeByIndex(int index)
{
    if (index < 0 || index >= _size)
    {
        return false;
    }

    Node* nodeToDelete = GetNodeByIndex(index);

    // Если удаляем голову
    if (nodeToDelete == _head)
    {
        _head = nodeToDelete->GetNextNode();
        if (_head != nullptr)
        {
            _head->SetPreviousNode(nullptr);
        }
        else
        {
            // Список стал пустым
            _tail = nullptr; 
        }
    }
    // Если удаляем хвост
    else if (nodeToDelete == _tail)
    {
        _tail = nodeToDelete->GetPreviousNode();
        if (_tail != nullptr)
        {
            _tail->SetNextNode(nullptr);
        }
        else
        {
            _head = nullptr;
        }
    }
    // Удаление из середины
    else
    {
        Node* prev = nodeToDelete->GetPreviousNode();
        Node* next = nodeToDelete->GetNextNode();

        prev->SetNextNode(next);
        next->SetPreviousNode(prev);
    }

    delete nodeToDelete;
    _size--;
    return true;
}

void List::RemoveNodeByValue(int value)
{
    Node* current = _head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->GetData() == value)
        {
            RemoveNodeByIndex(index);
            return; // Удаляем только первое вхождение
        }
        current = current->GetNextNode();
        index++;
    }
}

void List::Sort()
{
    if (_size < 2) return;

    for (int i = 0; i < _size - 1; i++)
    {
        Node* current = _head;
        for (int j = 0; j < _size - i - 1; j++)
        {
            Node* next = current->GetNextNode();
            if (current->GetData() > next->GetData())
            {
                // Обмен значениями данных 
                // (проще и безопаснее, чем перестановка указателей)
                int temp = current->GetData();
                current->SetData(next->GetData());
                next->SetData(temp);
            }
            current = next;
        }
    }
}

Node* List::FindNodeByValue(int value)
{
    Node* current = _head;
    while (current != nullptr)
    {
        if (current->GetData() == value)
        {
            return current;
        }
        current = current->GetNextNode();
    }
    return nullptr;
}

void List::Clean()
{
    while (_head != nullptr)
    {
        Node* temp = _head;
        _head = _head->GetNextNode();
        delete temp;
    }
    _tail = nullptr;
    _size = 0;
}