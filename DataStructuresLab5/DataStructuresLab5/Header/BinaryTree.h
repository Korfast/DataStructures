#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "BinaryTreeNode.h"

//! \brief Структура бинарного дерева поиска.
//!
//! Реализует основные операции над бинарным деревом поиска:
//! вставку, удаление, поиск элементов и нахождение узлов
//! с минимальным и максимальным значениями.
struct BinaryTree
{
private:
    //! \brief Указатель на корень дерева.
    BinaryTreeNode* _root;

    //! \brief Рекурсивное удаление всех узлов дерева.
    //! \param node Текущий узел для удаления.
    void Clear(BinaryTreeNode* node);

    //! \brief Вспомогательный метод для рекурсивного поиска.
    //! \param node Текущий узел.
    //! \param value Искомое значение.
    //! \return Указатель на найденный узел или nullptr.
    BinaryTreeNode* Search(BinaryTreeNode* node, int value);

public:
    //! \brief Создает пустое дерево.
    BinaryTree();

    //! \brief Освобождает память, занятую деревом.
    ~BinaryTree();

    //! \brief Добавляет новый элемент в дерево.
    //! \param value Значение для добавления.
    void AddElement(int value);

    //! \brief Удаляет элемент из дерева по значению.
    //! \param value Значение для удаления.
    void RemoveElement(int value);

    //! \brief Ищет элемент в дереве.
    //! \param value Искомое значение.
    //! \return Указатель на узел или nullptr, если не найден.
    BinaryTreeNode* FindElement(int value);

    //! \brief Находит узел с минимальным значением.
    //! \return Указатель на узел с минимальным значением.
    BinaryTreeNode* GetMinNode();

    //! \brief Находит узел с максимальным значением.
    //! \return Указатель на узел с максимальным значением.
    BinaryTreeNode* GetMaxNode();

    //! \brief Возвращает корень дерева.
    //! \return Указатель на корневой узел.
    BinaryTreeNode* GetRoot();
};

#endif // __BINARY_TREE_H__