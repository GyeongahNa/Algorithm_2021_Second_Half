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

int dp[1001][3];

int main() {

    int N, r, g, b;
    scanf("%d %d %d %d", &N, &r, &g, &b);
    dp[1][0] = r, dp[1][1] = g, dp[1][2] = b;

    for (int i=2; i<=N; i++) {
        scanf("%d %d %d", &r, &g, &b);
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b;
    }
    
    int re = 1001*N;
    for (int i=0; i<=2; i++) re = min(re, dp[N][i]);
    printf("%d", re);
    return 0;
}