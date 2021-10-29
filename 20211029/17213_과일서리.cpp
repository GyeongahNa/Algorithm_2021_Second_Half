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

int dp[11][31];

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<31; i++)
        dp[1][i] = 1;
    
    for (int j=2; j<11; j++) { 
        for (int i=1; i<31; i++) {
            if (j > i) continue;
            if (j == i) { dp[j][i] = 1; continue; }
            for (int k=1; k<=i-j+1; k++)
                dp[j][i] += dp[j-1][i-k];
        }
    }

    printf("%d", dp[N][M]);
    return 0;
}