#include <iostream>
using namespace std;

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode, *LinkStack;

LinkStack S; // stack

bool InitStack(LinkStack &S){
	S = NULL;
	return true;
}

bool StackEmpty(LinkStack S){
	if(S == NULL) return true;
	return false;
}

bool push(LinkStack &S, int e){
	StackNode* p = (StackNode*)malloc(sizeof(LinkStack));
	// p = new StackNode;
	p->data = e;
	p-> next = S;
	S = p;
	return true;
}
bool pop(LinkStack &S, int &e){
	if(S == NULL) return false;
	StackNode* p  = (StackNode*)malloc(sizeof(LinkStack));
	e = S -> data;
	p = S;
	S = S -> next;
	delete p;
	return true;
}

int GetTop(LinkStack S){
	if(S != NULL)
		return S -> data;
}
