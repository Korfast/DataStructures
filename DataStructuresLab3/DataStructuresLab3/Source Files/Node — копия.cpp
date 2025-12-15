#include "../Header Files/Node.h"

/**
 * Реализация конструктора Node.
 * @param val Значение, которое будет храниться в узле.
 * @param nextNode Указатель на следующий узел (по умолчанию nullptr).
 */
Node::Node(int val, Node* nextNode) : data(val), next(nextNode) {}