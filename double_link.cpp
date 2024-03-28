#include <cstddef>
#include <iostream>
using namespace std;

int n;

typedef struct node{
	int data;
	struct node* prior;
	struct node* next;
}dlink;

dlink* crelink(int n){
	dlink *head, *p, *s;
	p = head = (dlink*)malloc(sizeof(dlink));
	for(int i = 1;i <= n;i++){
		s = (dlink*)malloc(sizeof(dlink));
		cin >> s -> data;
		s -> prior = p;
		p -> next = s;
		p = s;
	}
	p -> next = head -> prior = NULL;
	return head;
}

int insert(dlink* head, int i, int n){
	dlink *p, *q;
	if(i < 1) return 0;
	p = head;
	int j = 0;
	while(p -> next != NULL && j < i - 1){
		j++;
		p = p -> next;
	}
	if()
}

int main(){
	cin >> n;
	crelink(n);
	
}
