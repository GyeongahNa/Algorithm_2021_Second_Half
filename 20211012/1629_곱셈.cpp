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

int solve(int A, int B, int C) {
    
    if (B == 0) return 1;
    int tmp = solve(A, B/2, C);
    if (B%2 == 0) return (1LL * tmp * tmp) % C; 
    return (1LL * tmp * tmp) % C * A % C;
}

int main() {

    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%lld", solve(A, B, C));
    return 0;
}