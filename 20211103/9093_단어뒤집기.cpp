#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    cin.ignore();
    
    while (N--) {
        
        string s;
        getline(cin, s);
        s += " ";
        
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != ' ') st.push(s[i]);
            else {
                while (!st.empty()) {
                    printf("%c", st.top());
                    st.pop();
                }
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}