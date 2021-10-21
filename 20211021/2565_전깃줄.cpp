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

int dp[101];

int main() {

    int N;
    scanf("%d", &N);

    vector<ii> v(N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end());


    int re = 1; dp[0] = 1;
    for (int i=1; i<N; i++) {
        int maxdp = 0;
        for (int j=0; j<i; j++) {
            if (v[j].second > v[i].second) continue;
            maxdp = max(dp[j], maxdp);
        }
        dp[i] = maxdp+1;
        re = max(dp[i], re);
    }
    printf("%d", N-re);
    return 0;
}