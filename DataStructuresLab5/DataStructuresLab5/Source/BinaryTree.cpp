#include "../Header/BinaryTree.h"

BinaryTree::BinaryTree()
{
    _root = nullptr;
}

BinaryTree::~BinaryTree()
{
    Clear(_root);
}

void BinaryTree::Clear(BinaryTreeNode* node)
{
    if (node != nullptr)
    {
        Clear(node->GetLeft());
        Clear(node->GetRight());
        delete node;
    }
}

void BinaryTree::AddElement(int value)
{
    if (_root == nullptr)
    {
        _root = new BinaryTreeNode(value);
        return;
    }

    BinaryTreeNode* current = _root;
    while (true)
    {
        if (value < current->GetValue())
        {
            if (current->GetLeft() == nullptr)
            {
                current->SetLeft(new BinaryTreeNode(value));
                break;
            }
            current = current->GetLeft();
        }
        else
        {
            if (current->GetRight() == nullptr)
            {
                current->SetRight(new BinaryTreeNode(value));
                break;
            }
            current = current->GetRight();
        }
    }
}

BinaryTreeNode* BinaryTree::FindElement(int value)
{
    return Search(_root, value);
}

BinaryTreeNode* BinaryTree::Search(BinaryTreeNode* node, int value)
{
    if (node == nullptr || node->GetValue() == value)
    {
        return node;
    }

    if (value < node->GetValue())
    {
        return Search(node->GetLeft(), value);
    }
    return Search(node->GetRight(), value);
}

void BinaryTree::RemoveElement(int value)
{
    BinaryTreeNode* current = _root;
    BinaryTreeNode* parent = nullptr;

    // Поиск узла и его родителя
    while (current != nullptr && current->GetValue() != value)
    {
        parent = current;
        if (value < current->GetValue())
            current = current->GetLeft();
        else
            current = current->GetRight();
    }

    if (current == nullptr) return;

    // Случай 1 и 2: Узла нет или один потомок
    if (current->GetLeft() == nullptr || current->GetRight() == nullptr)
    {
        BinaryTreeNode* newNode = (current->GetLeft() == nullptr)
            ? current->GetRight() : current->GetLeft();

        if (parent == nullptr)
            _root = newNode;
        else if (parent->GetLeft() == current)
            parent->SetLeft(newNode);
        else
            parent->SetRight(newNode);

        delete current;
    }
    else // Случай 3: Два потомка
    {
        BinaryTreeNode* successorParent = current;
        BinaryTreeNode* successor = current->GetRight();
        while (successor->GetLeft() != nullptr)
        {
            successorParent = successor;
            successor = successor->GetLeft();
        }

        current->SetValue(successor->GetValue());
        if (successorParent->GetLeft() == successor)
            successorParent->SetLeft(successor->GetRight());
        else
            successorParent->SetRight(successor->GetRight());

        delete successor;
    }
}

BinaryTreeNode* BinaryTree::GetMinNode()
{
    if (_root == nullptr) return nullptr;
    BinaryTreeNode* current = _root;
    while (current->GetLeft() != nullptr)
        current = current->GetLeft();
    return current;
}

BinaryTreeNode* BinaryTree::GetMaxNode()
{
    if (_root == nullptr) return nullptr;
    BinaryTreeNode* current = _root;
    while (current->GetRight() != nullptr)
        current = current->GetRight();
    return current;
}

BinaryTreeNode* BinaryTree::GetRoot()
{
    return _root;
}