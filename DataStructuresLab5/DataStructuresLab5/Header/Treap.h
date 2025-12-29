#ifndef __TREAP_H__
#define __TREAP_H__

#include "TreapNode.h"

//! \brief Структура декартового дерева (Treap).
struct Treap
{
private:
    //! \brief Корень декартового дерева.
    TreapNode* _root;

    //! \brief Разделяет дерево на два поддерева.
    void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

    //! \brief Сливает два дерева в одно.
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    //! \brief Рекурсивное освобождение памяти.
    void Clear(TreapNode* node);

    //! \brief Рекурсивная оптимизированная вставка.
    TreapNode* AddOptimizedInternal(TreapNode* node, int key, int priority);

    //! \brief Рекурсивное оптимизированное удаление.
    TreapNode* RemoveOptimizedInternal(TreapNode* node, int key);

public:
    Treap();
    ~Treap();

    TreapNode* GetRoot();

    //! \brief Ищет узел по ключу.
    TreapNode* Find(int key);

    //! \brief Добавление (Split/Merge).
    void AddUnoptimized(int key, int priority);

    //! \brief Добавление (один проход).
    void AddOptimized(int key, int priority);

    //! \brief Удаление (Split/Merge).
    void RemoveUnoptimized(int key);

    //! \brief Удаление (один проход).
    void RemoveOptimized(int key);
};

#endif // __TREAP_H__