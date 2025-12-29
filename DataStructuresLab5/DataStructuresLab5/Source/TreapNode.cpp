#include "../Header/TreapNode.h"

TreapNode::TreapNode(int key, int priority)
{
    _key = key;
    _priority = priority;
    _left = nullptr;
    _right = nullptr;
}

int TreapNode::GetKey() { return _key; }
void TreapNode::SetKey(int key) { _key = key; }

int TreapNode::GetPriority() { return _priority; }
void TreapNode::SetPriority(int priority) { _priority = priority; }

TreapNode* TreapNode::GetLeft() { return _left; }
void TreapNode::SetLeft(TreapNode* left) { _left = left; }

TreapNode* TreapNode::GetRight() { return _right; }
void TreapNode::SetRight(TreapNode* right) { _right = right; }