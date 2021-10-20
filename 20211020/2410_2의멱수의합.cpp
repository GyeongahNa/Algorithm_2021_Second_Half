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

long long dp[1000001];

int main() {

    int N;
    scanf("%d", &N);

    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<1000001; i++) {
        if (i%2) dp[i] = dp[i-1];
        else dp[i] = (dp[i-1]+dp[i/2])%1000000000;
    }
    printf("%lld", dp[N]);
    return 0;
}