#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int dp[1000001];

int main() {
    
    int N;
    scanf("%d", &N);

    dp[1] = 0; dp[2] = 1; dp[3] = 1;
    for (int i=4; i<=N; i++) {
        dp[i] = dp[i-1]+1;
        if (i%3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
        if (i%2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
    }
    
    printf("%d", dp[N]);
    return 0;
}