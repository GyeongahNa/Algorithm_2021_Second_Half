#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

long long dp[90][2];

int main() {
    
    int N;
    scanf("%d", &N);
    memset(dp, 0, sizeof(dp));
    
    dp[1][1] = 1;
    for (int i=2; i<=N; i++) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][1]+dp[i-1][0];
    }
    
    printf("%lld", dp[N][0]+dp[N][1]);
    return 0;
}