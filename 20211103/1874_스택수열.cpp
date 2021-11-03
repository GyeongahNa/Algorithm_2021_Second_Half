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
    
    stack<int> st;
    string ans = "";
    int m = 0;

    while (N--) {
        
        int x;
        scanf("%d", &x);
        
        if (x > m) {
            while (x > m) {
                st.push(++m);
                ans+="+\n";
            }
            st.pop();
            ans+="-\n";
        }
        else {
            if (st.empty() || st.top() != x) {
                ans = "NO\n";
                break;
            }
            st.pop();
            ans+="-\n";
        }
    }
    
    printf("%s", ans.c_str());
    return 0;
}