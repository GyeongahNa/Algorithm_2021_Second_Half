#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int stack[10001];
int sz = 0;

void push(int X) {
    
    stack[sz] = X;
    sz++;
    return ;
}

void pop() {
    
    if (sz == 0) {
        printf("%d\n", -1);
        return ;
    }
    printf("%d\n", stack[sz-1]);
    stack[sz-1] = 0;
    sz--;
    return ;
}

void size() {
    
    printf("%d\n", sz);
    return;
}

void empty() {
    
    if (sz == 0) {
        printf("1\n");
        return ;
    }
    printf("0\n");
    return ;
}

void top() {
    
    if (sz == 0) {
        printf("%d\n", -1);
        return ;
    }
    printf("%d\n", stack[sz-1]);
    return ;
}

int main() {
    
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push") {
            int X;
            scanf("%d", &X);
            push(X);
        }
        else if (cmd == "pop") pop();
        else if (cmd == "size") size();
        else if (cmd == "empty") empty();
        else top();
    }
}