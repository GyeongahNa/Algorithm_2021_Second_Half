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

int cnt[100001];

int main() {

    int N, K;
    scanf("%d %d", &N, &K);
    memset(cnt, 0, sizeof(cnt));

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    int re = 0;
    int st = 0, end = 0;
    while (st < N) {

        if (cnt[v[st]] < K) {
            cnt[v[st]]++;
            st++;
        }
        else {
            cnt[v[end]]--;
            end++;
        }
        re =  max(re , st-end);
    }
    printf("%d", re);
    return 0;
}