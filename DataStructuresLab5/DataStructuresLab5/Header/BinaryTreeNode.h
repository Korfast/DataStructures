#ifndef __BINARY_TREE_NODE_H__
#define __BINARY_TREE_NODE_H__

//! \brief Узел бинарного дерева поиска.
//!
//! Данная структура представляет собой базовый элемент 
//! бинарного дерева, хранящий целочисленное значение 
//! и ссылки на левое и правое поддеревья.
struct BinaryTreeNode
{
private:
    //! \brief Значение, хранящееся в узле.
    int _value;

    //! \brief Указатель на левого потомка.
    BinaryTreeNode* _left;

    //! \brief Указатель на правого потомка.
    BinaryTreeNode* _right;

public:
    //! \brief Инициализирует новый экземпляр узла.
    //! \param value Целочисленное значение для хранения в узле.
    BinaryTreeNode(int value);

    //! \brief Получает значение узла.
    //! \return Целочисленное значение.
    int GetValue();

    //! \brief Устанавливает новое значение узла.
    //! \param value Новое значение.
    void SetValue(int value);

    //! \brief Получает указатель на левого потомка.
    //! \return Указатель на левый узел или nullptr.
    BinaryTreeNode* GetLeft();

    //! \brief Устанавливает указатель на левого потомка.
    //! \param left Указатель на новый левый узел.
    void SetLeft(BinaryTreeNode* left);

    //! \brief Получает указатель на правого потомка.
    //! \return Указатель на правый узел или nullptr.
    BinaryTreeNode* GetRight();

    //! \brief Устанавливает указатель на правого потомка.
    //! \param right Указатель на новый правый узел.
    void SetRight(BinaryTreeNode* right);
};

#endif // __BINARY_TREE_NODE_H__