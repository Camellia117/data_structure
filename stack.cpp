#include <cmath>
#include <iostream>
#include <random>
using namespace std;

const int MAXSIZE = 100;

typedef struct{
	int* base;
	int* top;
	int stacksize;
}SqStack;

// init
bool InitStack(SqStack &S){
	S.base = new int[MAXSIZE];
	if(!S.base) exit(OVERFLOW); // 分配失败
	S.top = S.base; // 栈顶和栈底相等
	S.stacksize = MAXSIZE;
	return true;
}

// stack empty???
bool StackEmpty(SqStack S){
	if(S.top == S.base)
		return true;
	return false;
}

// get length
int StackLength(SqStack S){
	return S.top - S.base;
}

bool ClearStack(SqStack S){
	if(S.base) S.top = S.base; // 如果栈存在
	return true;
}

bool DestroyStack(SqStack &S){
	if(S.base){
		delete S.base;
		S.stacksize = 0;
		S.top = S.top = NULL; // I can't understand it
	}
	return true;
}

bool push(SqStack &S, int e){
	// stack have been full
	if(S.top - S.base == S.stacksize) return false;

	*S.top++ = e;
	return true;
}

bool pop(SqStack &S, int &e){
	if(StackEmpty(S)) return false;
	
	e = *--S.top;
	return true;
}


