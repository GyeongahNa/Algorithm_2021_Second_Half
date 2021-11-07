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
    
    char s[1000];
    memset(s, '\0', sizeof(s));
    scanf("%s", s);
    
    stack<char> st;

    int i = 0;
    string re = "";
    while (s[i] != '\0') {
        if (s[i] >= 'A' && 'Z' >= s[i]) re+=s[i];
        else if (s[i] == '(') st.push('(');
        else if (s[i] == '+' || s[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                re+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                re+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                re+=st.top();
                st.pop();
            }
            st.pop();
        }
        i++;
    }
    
    while (!st.empty()) {
        re+=st.top();
        st.pop();
    }

    printf("%s", re.c_str());
    return 0;
}