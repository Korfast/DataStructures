#ifndef __IO_TREAP_H__
#define __IO_TREAP_H__

#include "Treap.h"

//! \brief Функции ввода-вывода для декартового дерева.
namespace IOTreap
{
    //! \brief Выводит декартово дерево в консоль.
    //! \param node Текущий узел.
    //! \param level Уровень вложенности.
    void Print(TreapNode* node, int level = 0);
}

#endif // __IO_TREAP_H__