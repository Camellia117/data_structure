#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef  int ElementType;
typedef struct LQNode* LinkQueue;
struct Node{
	ElementType Data;
	struct Node* next;
};
struct LQNode{
	struct Node* front;
	struct Node* rear;
};
LinkQueue MakeEmptyLinkQueue();
void PushLinkQueue(LinkQueue Q, ElementType x);
ElementType PopLinkQueue(LinkQueue Q);
bool LinkQueueIsEmpty(LinkQueue Q);
void PintLinkQueue(LinkQueue Q);
#endif
