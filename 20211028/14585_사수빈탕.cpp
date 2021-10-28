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

int dp[301][301];
int dist[301][301];
int candy[301][301];

int main() {

    int N, M;
    scanf("%d %d", &N, &M);;
    memset(dp, 0, sizeof(dp));
    memset(dist, 0, sizeof(dist));
    memset(candy, 0, sizeof(candy));

    for (int i=0; i<N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        candy[y][x] = M;
    }

    int maxdp = 0;
    for (int i=0; i<301; i++) {
        for (int j=0; j<301; j++) {
            if (i==0 && j==0) continue;
            if ((j==0 && i > 0) || ((j > 0 && i > 0) && (dp[i-1][j] > dp[i][j-1]))) {
                dist[i][j] = dist[i-1][j]+1;
                dp[i][j] = dp[i-1][j];
            }
            else {
                dist[i][j] = dist[i][j-1]+1;
                dp[i][j] = dp[i][j-1];
            }
            if (candy[i][j]-dist[i][j] > 0) 
                dp[i][j] += (candy[i][j]-dist[i][j]);
            
            maxdp = max(maxdp, dp[i][j]);
        }
    }
    printf("%d", maxdp);
    return 0;
}