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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int M;
    cin >> M;
    
    stack<char> st1, st2;
    for (int i=0; i<s.size(); i++) 
        st1.push(s[i]);
    
    while (M--) {
        
        char cmd;
        cin >> cmd;
        
        if (cmd == 'L' && !st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        else if (cmd == 'D' && !st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        else if (cmd == 'B' && !st1.empty())
            st1.pop();
        else if (cmd == 'P') {
            char c;
            cin >> c;
            st1.push(c);
        }
    }
    
    while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }
    
    while (!st2.empty()) {
        cout << st2.top();
        st2.pop();
    }
    
    return 0;
}