/*
实现一个单链表，链表初始为空，支持三种操作：
(1) 向链表头插入一个数；
(2) 删除第k个插入的数后面的数；
(3) 在第k个插入的数后插入一个数
现在要对该链表进行t次操作，进行完所有操作后，从头到尾输出整个链表。
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100010;
int e[N],ne[N],idx,head;

void init(){ // 初始化
    head = -1;
    idx = 0;
}

void add_head(int x){ //在头结点后插入
    e[idx] = x; // 插入的数
    ne[idx] = head; // 将新插入的这个数指向头结点指向的数的位置
    head = idx; // 让头结点指向新插入的这个数
    idx++; // 链表长度++;
}

void add(int k,int x){ // 在第k个插入的数后面插入一个数
    e[idx] = x; 
    ne[idx] = ne[k]; // 将新插入的这个数指向第k个插入的数后面的数的位置
    ne[k] = idx;
    idx++;
}

void remove(int k){ // 删除第k个插入的数后面的数
    ne[k] = ne[ne[k]]; // 只需要让第 k 个数把第 k+1 个数的指针指向它的后面的数
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    init();
    int t; cin >> t;
    while (t--){
        char op; cin >> op; // 输入操作符 D 为删除，H 为插入，I 为插入
        int k,x;
        if(op == 'D'){
            cin >> k;
            if(!k) head = ne[head];
            remove(k - 1);
        }else if(op == 'H'){
            cin >> x;
            add_head(x);
        }else if(op == 'I'){
            cin >> k >> x;
            add(k - 1,x);
        }
    }
    for(int i = head;i != -1;i =ne[i]){
        cout << e[i] << " ";
    }
    return 0;
}