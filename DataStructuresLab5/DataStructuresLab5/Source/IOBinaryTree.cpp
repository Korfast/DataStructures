#include "../Header/IOBinaryTree.h"
#include <iostream>
#include <iomanip>

using namespace std;

void IOBinaryTree::Print(BinaryTreeNode* node, int level)
{
    if (node == nullptr) return;

    // Сначала печатаем правое поддерево (оно будет сверху)
    Print(node->GetRight(), level + 1);

    for (int i = 0; i < level; i++) cout << "    ";
    cout << "|--" << node->GetValue() << endl;

    // Затем левое поддерево
    Print(node->GetLeft(), level + 1);
}