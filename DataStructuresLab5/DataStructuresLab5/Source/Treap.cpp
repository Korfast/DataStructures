#include "../Header/Treap.h"

Treap::Treap() : _root(nullptr) {}

Treap::~Treap() { Clear(_root); }

void Treap::Clear(TreapNode* node)
{
    if (node != nullptr)
    {
        Clear(node->GetLeft());
        Clear(node->GetRight());
        delete node;
    }
}

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
    if (node == nullptr)
    {
        left = right = nullptr;
        return;
    }

    if (node->GetKey() < key)
    {
        TreapNode* tempRight = node->GetRight();
        Split(tempRight, key, tempRight, right);
        node->SetRight(tempRight);
        left = node;
    }
    else
    {
        TreapNode* tempLeft = node->GetLeft();
        Split(tempLeft, key, left, tempLeft);
        node->SetLeft(tempLeft);
        right = node;
    }
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
    if (left == nullptr || right == nullptr)
        return (left != nullptr) ? left : right;

    if (left->GetPriority() > right->GetPriority())
    {
        left->SetRight(Merge(left->GetRight(), right));
        return left;
    }
    else
    {
        right->SetLeft(Merge(left, right->GetLeft()));
        return right;
    }
}

void Treap::AddUnoptimized(int key, int priority)
{
    TreapNode* l, * r;
    Split(_root, key, l, r);
    TreapNode* newNode = new TreapNode(key, priority);
    _root = Merge(Merge(l, newNode), r);
}

void Treap::AddOptimized(int key, int priority)
{
    _root = AddOptimizedInternal(_root, key, priority);
}

TreapNode* Treap::AddOptimizedInternal(TreapNode* node, int key, int priority)
{
    if (node == nullptr)
        return new TreapNode(key, priority);

    if (priority > node->GetPriority())
    {
        TreapNode* newNode = new TreapNode(key, priority);
        TreapNode* l, * r;
        Split(node, key, l, r);
        newNode->SetLeft(l);
        newNode->SetRight(r);
        return newNode;
    }

    if (key < node->GetKey())
    {
        node->SetLeft(AddOptimizedInternal(node->GetLeft(), key, priority));
    }
    else
    {
        node->SetRight(AddOptimizedInternal(node->GetRight(), key, priority));
    }

    return node;
}

void Treap::RemoveUnoptimized(int key)
{
    TreapNode* l, * m, * r;
    Split(_root, key, l, r);
    Split(r, key + 1, m, r);
    delete m;
    _root = Merge(l, r);
}

void Treap::RemoveOptimized(int key)
{
    _root = RemoveOptimizedInternal(_root, key);
}

TreapNode* Treap::RemoveOptimizedInternal(TreapNode* node, int key)
{
    if (node == nullptr) return nullptr;

    if (node->GetKey() == key)
    {
        TreapNode* temp = Merge(node->GetLeft(), node->GetRight());
        delete node;
        return temp;
    }

    if (key < node->GetKey())
        node->SetLeft(RemoveOptimizedInternal(node->GetLeft(), key));
    else
        node->SetRight(RemoveOptimizedInternal(node->GetRight(), key));

    return node;
}

TreapNode* Treap::Find(int key)
{
    TreapNode* current = _root;
    while (current != nullptr && current->GetKey() != key)
    {
        if (key < current->GetKey())
            current = current->GetLeft();
        else
            current = current->GetRight();
    }
    return current;
}

TreapNode* Treap::GetRoot() { return _root; }