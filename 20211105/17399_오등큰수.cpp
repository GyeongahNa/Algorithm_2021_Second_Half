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

int freq[1000001];

int main() {

    int N;
    scanf("%d", &N);
    memset(freq, 0, sizeof(freq));

    vector<int> v(N), re(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &v[i]);
        freq[v[i]]++;
    }
    
    stack<int> st;
    st.push(0);

    for (int i=1; i<v.size(); i++) {

        while (!st.empty()) {
            if (freq[v[st.top()]] >= freq[v[i]]) break;
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