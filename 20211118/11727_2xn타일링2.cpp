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

int dp[1001];

// dp[n] = dp[n-1] + dp[n-2]*2 로 푸는 것이 더 합리적으로 보임
int main() {
    
    int N;
    scanf("%d", &N);
    
    dp[1] = 1; 
    for (int i=2; i<=N; i++) {
        if (i%2 == 0) dp[i] = (2*dp[i-1]+1)%10007;
        else dp[i] = (2*dp[i-1]-1)%10007;
    }
    printf("%d", dp[N]);
    return 0;
}