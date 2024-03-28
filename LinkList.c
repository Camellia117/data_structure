#include <stdio.h>
#include <stdlib.h>
#define NULL 0

typedef int ElemType;
typedef struct node{
		ElemType data;
		struct node* next;
}slink;
 
slink* crelink(int n){
		slink* p = (slink*)malloc(sizeof(struct node) * n);
		slink* head = p;
		p -> next = NULL;
		int i = 1;
		while(i <= n){
				p -> next = p + i;
		}
		return head;
}
void List(slink* head){
		slink* p = head -> next;
		while(p != NULL){
				printf("%d ", p -> data);
				p = p -> next;
		}
		printf("\n");
}
int getlen(slink* head){
		slink* p;
		p = head;
		int i = 0;
		while(p -> next != NULL){
				i++;
		}
		return i;
}
int getElem(slink* head, int i, ElemType* e){
	if(i < 1) return 0;
	slink* p = head;
	int j = 0;
	while(p != NULL && j == i){
		p = p -> next;
		j++;
	}
	if(p == NULL) return 0;
	*e = p -> data;
	return 1;
}

int insert(slink* head, int i, ElemType e){
	if(i < 1) return 0;
	int j = 0;
	slink* s = (slink*)malloc(sizeof(slink));
	s -> data = e;
	slink* p = head; // 方便在第一个节点前面插入
	while(p != NULL && j < i - 1){
		p = p -> next;
		j++;
	}
	if(p == NULL) return 0;
	s -> next = p -> next;
	p -> next = s;
	return 1;
}
int delete(slink* head, int i){
	slink* p = head;
	slink* q;
	int j = 0;
	while(p -> next != NULL && j < i - 1){
		p = p -> next;
		j++;
	}
	if(p -> next == NULL) return 0;
	q = p -> next;
	p -> next = q -> next;
	free(q);
	return 1;
}
int main(){

}
