#ifndef __IO_BINARY_TREE_H__
#define __IO_BINARY_TREE_H__

#include "BinaryTree.h"

//! \brief Функции ввода-вывода для бинарного дерева поиска.
namespace IOBinaryTree
{
    //! \brief Выводит дерево в консоль (горизонтально).
    //! \param node Текущий узел.
    //! \param level Уровень вложенности (для отступов).
    void Print(BinaryTreeNode* node, int level = 0);
}

#endif // __IO_BINARY_TREE_H__