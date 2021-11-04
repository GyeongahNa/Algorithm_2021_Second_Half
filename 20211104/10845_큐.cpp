#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;


struct Queue {

    int queue[20000];
    int begin, end;

    Queue() {
        begin = 0;
        end = 0;
    }

    void push(int x) {
        queue[end] = x;
        end++;
    }

    void pop() {
        if (begin == end) {
            printf("-1\n");
            return;
        }
        printf("%d\n", queue[begin]);
        queue[begin] = 0;
        begin++;
    }

    void size() {
        printf("%d\n", end-begin);
    }

    void empty() {
        printf("%d\n", (begin==end) ? 1 : 0);
    }

    void front() {
        if (begin == end) {
            printf("-1\n");
            return;
        }
        printf("%d\n", queue[begin]);
    }

    void back() {
        if (begin==end) {
            printf("-1\n");
            return;
        }
        printf("%d\n", queue[end-1]);
    }
};

int main() {
    
    int N;
    cin >> N;

    Queue q;
    
    while (N--) {
        
        string cmd;
        cin >> cmd;
        
        if (cmd == "push") {
            int X;
            cin >> X;
            q.push(X);
        }
        else if (cmd == "pop") q.pop();
        else if (cmd == "size") q.size();
        else if (cmd == "empty") q.empty();
        else if (cmd == "front") q.front();
        else q.back();
    }
    return 0;
}