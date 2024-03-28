#include <iostream>
#define int long long
using namespace std;

const int N = 100010;
int head,idx,e[N],l[N],r[N];


void init(){
    l[1] = 0,r[0] = 1;
    idx = 2;
}

void add(int k, int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
signed main(){
    init();
    int t; cin >> t;
    while(t--){
        string op;
        int k,x;
        cin >> op;
        if(op == "L"){
            int x; cin >> x;
            add(0,x);
        }else if(op == "R"){
            int x; cin >> x;
            add(l[1],x);
        }else if(op == "D"){
            int k; cin >> k;
            remove(k + 1);
        }else if(op == "IL"){
            int k,x; cin >> k >> x;
            add(l[k + 1],x);
        }else if(op == "IR"){
            int k,x; cin >> k >> x;
            add(k + 1, x);
        }
    }
    for(int i = r[0];i == -1;i = r[i]){
        cout << e[i] << " ";
    }
}
