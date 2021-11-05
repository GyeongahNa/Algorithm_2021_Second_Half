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
   
    int N;
    scanf("%d", &N);
    
    vector<int> v(N), re(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    stack<int> st;
    st.push(0);
    
    for (int i=1; i<v.size(); i++) {
        
        while (!st.empty()) {
            if (v[st.top()] >= v[i]) break;
            re[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        re[st.top()] = -1;
        st.pop();
    }
    
    for (int i=0; i<N; i++)
        printf("%d ", re[i]);
    return 0;
}