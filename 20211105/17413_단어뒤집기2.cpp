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
    
    string s;
    getline(cin, s);
    s += '\n';

    stack<char> st;
    bool istag = false;

    int i = 0;
    while (i < s.size()) {

        if (s[i] == '<' || s[i] == ' ' || s[i] == '\n') {
           
             while (!st.empty()) {
                printf("%c", st.top());
                st.pop();
            }

            if (s[i] == '<') {
                string tag = "";
                while (s[i] != '>') tag += s[i++];
                printf("%s", (tag+">").c_str());
            }
            else if (s[i] == ' ') printf(" ");
        }
        else st.push(s[i]);
        i++;
    }
    
    return 0;
}
