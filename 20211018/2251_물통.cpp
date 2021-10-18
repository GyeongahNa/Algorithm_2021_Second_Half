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

int A, B, C;
bool check[201][201][201];
vector<int> v;

int give(int from, int fBot, int to, int tBot) {

    if ((to+from) > tBot) return (tBot - to);
    return from;
}

void solve(int a, int b, int c) {

    if (check[a][b][c]) return;
    check[a][b][c] = true;

    if (a == 0) v.push_back(c);
    solve(a-give(a, A, b, B), b+give(a, A, b, B), c);
    solve(a-give(a, A, c, C), b, c+give(a, A, c, C));
    solve(a+give(b, B, a, A), b-give(b, B, a, A), c);
    solve(a, b-give(b, B, c, C), c+give(b, B, c, C));
    solve(a+give(c, C, a, A), b, c-give(c, C, a, A));
    solve(a, b+give(c, C, b, B), c-give(c, C, b, B));
    return ;
}

int main() {

    scanf("%d %d %d", &A, &B, &C);
    memset(check, false, sizeof(check));

    solve(0, 0, C);
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++)
        printf("%d ", v[i]);
    return 0;
}