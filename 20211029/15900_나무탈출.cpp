#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int distTotal = 0;
bool check[500001];
vector<int> tree[500001];

void bfs(int node, int dist) {

    check[node] = true;
    
    int numNext = 0;
    for (int i=0; i<tree[node].size(); i++) {
        if (check[tree[node][i]]) continue;
        bfs(tree[node][i], dist+1);
        numNext++;
    }

    if (numNext == 0) distTotal += dist;
}

int main() {

    int N;
    scanf("%d", &N);
    memset(check, false, sizeof(check));

    for (int i=0; i<N-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    bfs(1, 0);
    if (distTotal % 2) printf("Yes");
    else printf("No");
    return 0;
}