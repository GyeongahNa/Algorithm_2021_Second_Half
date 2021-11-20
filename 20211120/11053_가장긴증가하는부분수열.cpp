#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int dp[1000];

int main() {
    
    int N;
    scanf("%d", &N);
    
    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1;
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (v[j] >= v[i]) continue;
            dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
    }
    
    int re = 0;
    for (int i=0; i<N; i++)
        re = max(re, dp[i]);
    printf("%d", re);
    return 0;
}