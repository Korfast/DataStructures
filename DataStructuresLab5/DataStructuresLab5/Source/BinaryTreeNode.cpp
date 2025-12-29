#include "../Header/BinaryTreeNode.h"

//! \brief Конструктор узла.
BinaryTreeNode::BinaryTreeNode(int value)
{
    _value = value;
    _left = nullptr;
    _right = nullptr;
}

int BinaryTreeNode::GetValue()
{
    return _value;
}

void BinaryTreeNode::SetValue(int value)
{
    _value = value;
}

BinaryTreeNode* BinaryTreeNode::GetLeft()
{
    return _left;
}

void BinaryTreeNode::SetLeft(BinaryTreeNode* left)
{
    _left = left;
}

BinaryTreeNode* BinaryTreeNode::GetRight()
{
    return _right;
}

void BinaryTreeNode::SetRight(BinaryTreeNode* right)
{
    _right = right;
}