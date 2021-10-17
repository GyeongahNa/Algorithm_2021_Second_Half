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

int dp[10000];

int main() {

    int N;
    scanf("%d", &N);
    memset(dp, 0, sizeof(dp));
    
    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    dp[0] = v[0]; 
    dp[1] = v[0]+v[1];
    
    int maxval = 0;
    for (int i=2; i<N; i++) {
        dp[i] = max(maxval+v[i-1], max(maxval, dp[i-2]))+v[i];
        maxval = max(maxval, dp[i-2]);
    }

    int re = 0;
    for (int i=0; i<N; i++)
        re = max(re, dp[i]);
    printf("%d", re);
    return 0;
}