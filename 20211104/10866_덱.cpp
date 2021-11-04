#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main() {
    
    int N;
    cin >> N;
    
    deque<int> d;
    
    while (N--) {
        
        string cmd;
        cin >> cmd;
        
        if (cmd == "push_front") {
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if (cmd == "push_back") {
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if (cmd == "pop_front") {
            if (d.empty()) printf("-1\n");
            else {
                printf("%d\n", d.front());
                d.pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (d.empty()) printf("-1\n");
            else {
                printf("%d\n", d.back());
                d.pop_back();
            }
        }
        else if (cmd == "size") printf("%d\n", (int)d.size());
        else if (cmd == "empty") printf("%d\n", d.empty() ? 1 : 0);
        else if (cmd == "front") {
            if (d.empty()) printf("-1\n");
            else printf("%d\n", d.front());
        }
        else {
            if (d.empty()) printf("-1\n");
            else printf("%d\n", d.back());
        }
    }
    
    return 0;
}