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

int main() {
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    queue<int> q;
    for (int i=1; i<=N; i++)
        q.push(i);
    
    vector<int> v;
    while (!q.empty()) {
        
        for (int i=0; i<M-1; i++) {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }

    printf("<");
    for (int i=0; i<v.size()-1; i++)
        printf("%d, ", v[i]);
    printf("%d>", v[v.size()-1]);
    return 0;
}