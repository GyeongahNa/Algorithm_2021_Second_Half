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

int psum[1025][1025];

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    memset(psum, 0, sizeof(psum));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int n;
            scanf("%d", &n);
            psum[i][j] = psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+n;
        }
    }

    for (int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        printf("%d\n", psum[y2][x2]-psum[y2][x1-1]-psum[y1-1][x2]+psum[y1-1][x1-1]);
    }
    return 0;
}