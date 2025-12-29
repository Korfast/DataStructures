#ifndef __TREAP_NODE_H__
#define __TREAP_NODE_H__

//! \brief Узел декартового дерева (Treap).
//!
//! Данная структура объединяет свойства узла бинарного дерева поиска
//! и кучи (heap). Каждый узел обладает парой (Key, Priority).
struct TreapNode
{
private:
    //! \brief Ключ узла (для BST-свойства).
    int _key;

    //! \brief Приоритет узла (для Heap-свойства).
    int _priority;

    //! \brief Указатель на левого потомка.
    TreapNode* _left;

    //! \brief Указатель на правого потомка.
    TreapNode* _right;

public:
    //! \brief Инициализирует узел декартового дерева.
    //! \param key Ключ узла.
    //! \param priority Приоритет узла.
    TreapNode(int key, int priority);

    //! \brief Возвращает ключ узла.
    //! \return Значение ключа.
    int GetKey();

    //! \brief Устанавливает ключ узла.
    //! \param key Новое значение ключа.
    void SetKey(int key);

    //! \brief Возвращает приоритет узла.
    //! \return Значение приоритета.
    int GetPriority();

    //! \brief Устанавливает приоритет узла.
    //! \param priority Новое значение приоритета.
    void SetPriority(int priority);

    //! \brief Возвращает указатель на левого потомка.
    //! \return Указатель на левый узел или nullptr.
    TreapNode* GetLeft();

    //! \brief Устанавливает указатель на левого потомка.
    //! \param left Указатель на новый левый узел.
    void SetLeft(TreapNode* left);

    //! \brief Возвращает указатель на правого потомка.
    //! \return Указатель на правый узел или nullptr.
    TreapNode* GetRight();

    //! \brief Устанавливает указатель на правого потомка.
    //! \param right Указатель на новый правый узел.
    void SetRight(TreapNode* right);
};

#endif // __TREAP_NODE_H__