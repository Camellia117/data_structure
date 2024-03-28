#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int ElementType;
typedef struct LNode* List; // List是LNode类型指针

struct LNode {
  ElementType data[MAXSIZE];
  int Last;
};

struct LNode L;
List Ptrl; 

List MakeEmpty(){
  List Ptrl;
  Ptrl = (List)malloc(sizeof(struct LNode));
  Ptrl-> Last = -1;
  return Ptrl;
}

int Find(ElementType e,List Ptrl){
  int i = 0;
  while(i <= Ptrl-> Last && Ptrl-> data[i] != e) i++;
  if(i > Ptrl-> Last) return -1;
  return i;
}

void Insert(ElementType e, int i, List Ptrl){
  if(Ptrl-> Last == MAXSIZE - 1){
    printf("表满\n");
    return ;
  }  
  if(i < 1 || i > Ptrl-> Last + 2){
    printf("位置不合法\n");
    return ;
  }
  for(int j = Ptrl-> Last; j >= i;j--)
    Ptrl-> data[j + 1] = Ptrl-> data[j];
  Ptrl-> data[i] = e;
  Ptrl-> Last++; //更新last指针
}

ElementType FindValue(int k, List Ptrl){
  if(k < 0 || k > Ptrl-> Last){
     printf("Ptrl->date[%d]不存在元素",k);
    return NULL;
  }
  return Ptrl-> data[k];
}
void Detele(int k, List Ptrl){
  if(i < 1 || i > Ptrl-> Last + 1){
    printf("不存在第%d个元素",i);
    return ;
  }
  for(int j = i; j <= Ptrl-> Last; j++)
    Ptrl-> date[j - 1] = Ptrl-> date[j];
  Ptrl-> Last--;
}

int main(){
  Ptrl = MakeEmpty();
  int local = Find(5,Ptrl);
  Insert(6, 3, Ptrl);
  ElementType value = FindValue(4, Ptrl);
  Detele(2, Ptrl);
  return 0;
}
