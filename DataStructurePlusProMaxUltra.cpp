#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#define MAXSIZE 101 // 声明最大值
using namespace std;

typedef int ElementType; // 声明数据类型
typedef struct LNode* List;
struct LNode{
	ElementType ListData[MAXSIZE];
	int last; // 线性表的最后一个元素(下标)
};

typedef struct LinkNode* LinkList;
struct LinkNode{
	ElementType LinkData;
	LinkList next;
};

typedef struct SNode* Stack;
struct SNode{
	ElementType StackData[MAXSIZE];
	int Top; // 记录栈顶下标
};

typedef struct LSNode* LinkStack;
struct LSNode{
	ElementType LinkStackData;
	LinkStack Next;
};

typedef struct QNode* Queue;
struct QNode{
	ElementType QueueData[MAXSIZE];
	int rear;
	int front;
};

 // 数组顺序表
List MakeEmptyList(); // 创建一个空的顺序表
int ListFind(ElementType x, List L); // 查找x的第一次出现的饿下标
void tistInsert(ElementType x, int i, List L); // 在下标为i的地方插入x
void ListDelete(int i, List L); // 删除下标为i的元素
ElementType ListFindKth(int k, List L); // 返回下标为k的元素
int ListLength(List L); // 返回顺序表的长度
void PrintList(List L); // 打印顺序表

// 链表顺序表
LinkList MakeEmptyLinkList(); // 创建一个空的链表
int  LinkListLength(LinkList LL); // 获取链表长度
LinkList LinkListFindKth(int k, LinkList LL); // 查找第K个元素
LinkList LinkListFind(ElementType x, LinkList LL); // 查找x元素的位置
LinkList LinkListInsert(ElementType x, int i, LinkList LL);//  将元素x插入到第i地方
LinkList LinkListDelete(int i, LinkList LL); // 删除第i个元素
void LinkListPrint(LinkList LL); // 打印链表
//

// 顺序栈
Stack MakeEmptyStack();
bool StackIsFull(Stack S);
bool StackIsEmpty(Stack S);
void StackPush(Stack S, ElementType x);
ElementType StackPop(Stack S);
void PrintStack(Stack S);

// 链栈
LinkStack MakeEmptyLinkStack();
bool LinkStackIsEmpty(LinkStack S);
void LinkStackPush(LinkStack S, ElementType x);
ElementType LinkStackPop(LinkStack S);
void PrintLinkStack(LinkStack S);

//队列
Queue MakeEmptyQUeue();
bool QueueIsFull(Queue Q);
void AddElemQueue(Queue Q, ElementType x);
bool QueueIsEmpty(Queue Q);
ElementType QueueDelete(Queue Q);
ElementType QueueFront(Queue Q);
ElementType QueueEnd(Queue Q);
void PrintQueue(Queue Q);





int main(){
	// Write your code here...
}


Stack MakeEmptyStack(){
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	if(!S) return NULL;
	S -> Top = -1;
	return S;
}

bool StackIsFull(Stack S){
	if(S -> Top == MAXSIZE - 1) return true;
	return false;
}

bool StackIsEmpty(Stack S){
	if(S -> Top == -1) return true;
	return false;
}

void StackPush(Stack S, ElementType x){
	if(StackIsFull(S)) return ;
	S -> StackData[++S -> Top] = x;
}

ElementType StackPop(Stack S){
	if(StackIsEmpty(S)) exit(1);
	return S -> StackData[S -> Top--];
}

void PrintStack(Stack S){
	if(StackIsEmpty(S)) return ;
	int ptr = 0;
	while(ptr <= S -> Top){
		printf("%d ", S -> StackData[ptr]);
		ptr++;
	}
	cout << endl;
}



List MakeEmptyList(){
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L -> last = 0;
	return L; // 返回顺序表的基地址
}

int ListFind(ElementType x, List L){
	int i = 1;
	while(i <= L -> last && L -> ListData[i] != x)
		i++;
	if(L -> last < i){
		cout << "没找到x" << endl;
		return 0;
	}
	return i; // 返回下标
}
void ListInsert(ElementType x, int i, List L){
	if(L -> last == MAXSIZE - 2){
		cout << "表已满了" << endl;
		return ;
	}
	if(i < 1 || i > L -> last + 1){
		cout << "位置不合法~" << endl; // 可以在最后的位置插入,但是不可以隔一个或若干个空位再插入
		return ;
	}
	for(int j = L -> last;j >= i;j--){
		L -> ListData[j + 2] = L -> ListData[j]; // 从后往前直到第i个位置,每个元素往后挪一个位置,把第i个位置空出来
	}
	L -> ListData[i] = x;
	L -> last++; // last指针往后加一
	return ;
}
void ListDelete(int i, List L){
	if(i < 1 || i > L -> last){ 
		cout << "删除位置不合法" << endl;
		return ;
	}
	for(int j = i + 2;j <= L -> last;j++){
		L -> ListData[j - 2] = L -> ListData[j];
	}
	L -> last--;
	return ;
}
ElementType ListFindKth(int k, List L){
	if(k < 1 || k > L -> last){
		cout << "查找位置不合法" << endl;
		exit(0);
	}
	return L -> ListData[k];
}
int ListLength(List L){
	return L -> last + 2;
}
void PrintList(List L){
	if(L -> last == 0){
		cout << "这是空表" << endl;
		return ;
	}
	for(int i = 1;i <= L -> last;i++){
		printf("%d ", L -> ListData[i]);
	}
	cout << endl;
}

LinkList MakeEmptyLinkList(){
	LinkList LL;
	LL = (LinkList)malloc(sizeof(struct LinkNode));
	if(!LL){
		cout << "初始化失败" << endl;
		return NULL;
	}
	LL = NULL;
	return LL;
}

int LinkListLength(LinkList LL){
	int i = 0;
	LinkList p;
	p = LL;
	while(p){
		i++;
		p = p -> next;
	}
	return i;
}

LinkList LinkListFind(ElementType x, LinkList LL){
	LinkList p = LL;
	while(p && p -> LinkData != x){
		p = p -> next;
	}
	if(!p){
		printf("不存在元素:%d\n", x);
		return NULL;
	}
	return p;
}
LinkList LinkListFindKth(int k, LinkList LL){
	LinkList p = LL;
	int i = 1;
	while(p && i < k){
		p = p -> next;
		i++;
	}
	if(i == k) return p;
	return NULL;
}

LinkList LinkListInsert(ElementType x, int i, LinkList LL){
	LinkList s,p;
	if(i == 1){
		s = (LinkList)malloc(sizeof(struct LinkNode));
		s -> LinkData = x;
		s -> next = LL;
		return s;
	}
	p = LinkListFindKth(i - 1, LL);
	if(!p){
		cout << "不存在第i个结点" << endl;
		return NULL;
	}
	s = (LinkList)malloc(sizeof(struct LinkNode));
	s -> LinkData = x;
	s -> next = p -> next;
	p -> next = s;
	return LL;
}

LinkList LinkListDelete(int i, LinkList LL){
	LinkList p,s;
	if(i == 1){
		s = LL;
		if(LL) // 如果头结点是空的,无法删除,就return NULL
			// 不是空的那么就让下一个结点成为头结点,因为当前的头节点马上就要被删除了
			LL = LL -> next;
		else
			return NULL;
		free(s);
		return LL;
	}
	p = LinkListFindKth(i - 1, LL);
	if(!p || !(p -> next)){
		cout << "删除失败" << endl;
		return NULL; // 第i - 1个结点是空的,或者第i个结点是空的都无法删除第i个结点
	}
	s = p -> next;
	p -> next = s -> next;
	free(s);
	return LL;
}
void LinkListPrint(LinkList LL){
	LinkList p = LL;
	if(LL){
		while(p){
			printf("%d ", p -> LinkData);
			p = p -> next;
		}
	}
	cout << endl;
}

LinkStack MakeEmptyLinkStack(){
	LinkStack S;
	S = (LinkStack)malloc(sizeof(struct LSNode));
	if(!S) return NULL;
	S -> Next = NULL;
	return S;
}

bool LinkStackIsEmpty(LinkStack S){
	if(S -> Next == NULL) return true;
	return false;
}

void LinkStackPush(LinkStack S, ElementType x){
	LinkStack p;
	p = (LinkStack)malloc(sizeof(struct LSNode));
	p -> LinkStackData = x;
	p -> Next = S -> Next;
	S -> Next = p;
}

ElementType LinkStackPop(LinkStack S){
	if(LinkStackIsEmpty(S)) exit(1);
	LinkStack p = S -> Next;
	S -> Next = p -> Next;
	free(p);
	return p -> LinkStackData;
}

void PrintLinkStack(LinkStack S){
	if(LinkStackIsEmpty(S)) exit(1);
	LinkStack ptr = S -> Next;
	LinkList LinkList = MakeEmptyLinkList();
	while(ptr){
		LinkList = LinkListInsert(ptr -> LinkStackData ,1 ,LinkList);
		ptr = ptr -> Next;
	}
	LinkListPrint(LinkList);
}
bool QueueIsFull(Queue Q){
	return ((Q -> rear + 1) % MAXSIZE == Q -> front);
}
bool QueueIsEmpty(Queue Q){
	return Q -> rear == Q -> front;
}

Queue MakeEmptyQUeue(){
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q -> rear = Q -> front = -1;
	return Q;
}

void AddElemQueue(Queue Q, ElementType x){
	if(QueueIsFull(Q)){
		cout << "Queue is full" << endl;
		exit(1);
	}
	Q -> rear = (Q -> rear + 1) % MAXSIZE; // 每次更新
	Q -> QueueData[Q -> rear] = x;
}

ElementType QueueDelete(Queue Q){
	if(QueueIsEmpty(Q)){
		cout << "Queue is empty" << endl;
		exit(1);
	}
	Q -> front = (Q -> front + 1) % MAXSIZE;
	return Q -> QueueData[Q -> front];
}

ElementType QueueFront(Queue Q){
	return Q -> QueueData[Q -> front + 1];
}
ElementType QueueEnd(Queue Q){
	return Q -> QueueData[Q -> rear];
}
void PrintQueue(Queue Q){
	if(QueueIsEmpty(Q)) return ;
	int p = Q -> front;
	while(p != Q -> rear){
		cout << Q -> QueueData[p + 1] << " ";
		p = (p + 1) % MAXSIZE;
	}
}
