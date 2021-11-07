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
    
    string s;
    cin >> s;
    
    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    stack<double> st;
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            st.push(v[s[i]-'A']);
        else {
            double n2 = st.top();
            st.pop();
            double n1 = st.top();
            st.pop();
            
            if (s[i] == '*') st.push(n1*n2);
            if (s[i] == '/') st.push(n1/n2);
            if (s[i] == '+') st.push(n1+n2);
            if (s[i] == '-') st.push(n1-n2);
        }
    }
    
    printf("%.2f", st.top());
    return 0;
}