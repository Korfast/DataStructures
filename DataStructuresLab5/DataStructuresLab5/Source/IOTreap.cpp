#include "../Header/IOTreap.h"
#include <iostream>

using namespace std;

void IOTreap::Print(TreapNode* node, int level)
{
    if (node == nullptr) return;

    Print(node->GetRight(), level + 1);

    for (int i = 0; i < level; i++) cout << "    ";
    // Выводим и ключ, и приоритет
    cout << "|--{" << node->GetKey() << ";" << node->GetPriority() << "}" << endl;

    Print(node->GetLeft(), level + 1);
}