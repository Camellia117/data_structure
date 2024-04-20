#include <iostream>
#include "Head/LinkQueue.h"

 
LinkQueue MakeEmptyLinkQueue(){
	LinkQueue Q;
	Q = (LinkQueue)malloc(sizeof(struct LQNode));
	Q -> front = NULL;
	Q -> rear = NULL;
	return Q;
}

bool LinkQueueIsEmpty(LinkQueue Q){
	return (Q -> front == NULL);
}

void PushLinkQueue(LinkQueue Q, ElementType x){
	struct Node* node;
	node = (struct Node*)malloc(sizeof(struct Node)); // 声明新的结点
	node -> Data = x;
	node -> next = NULL;
	if(LinkQueueIsEmpty(Q)){ // 如果此时队列是空的,
		// 那就让队头和队尾指向第一个元素
		Q -> rear = node;
		Q -> front = node; 
	}else{
		Q -> rear -> next = node;
		Q -> rear = node;
	}
}

ElementType PopLinkQueue(LinkQueue Q){
	struct Node* tmp;
	ElementType tmpx;
	if(LinkQueueIsEmpty(Q)){
		std::cout << "队列空" << std::endl;
		exit(1);
	}
	tmp = Q -> front;
	if(Q -> front == Q -> rear){
		Q -> front = Q -> rear = NULL; //如果队列中仅有一个元素
	}else{
		Q -> front = Q -> front -> next;
	}
	tmpx = tmp -> Data;
	free(tmp);
	return tmpx;
}

void PintLinkQueue(LinkQueue Q){
	if(LinkQueueIsEmpty(Q)){
		std::cout << "队列空" << std::endl;
		exit(1);
	}
	struct Node* tmp;
	tmp = Q -> front;
	while(tmp != NULL){
		std::cout << tmp -> Data << " ";
		tmp = tmp -> next;
	}
}
