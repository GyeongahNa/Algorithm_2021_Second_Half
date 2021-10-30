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

int main() {

    int a, d, k;
    scanf("%d %d %d", &a, &d, &k);

    double bef = d/100.0, num = 1;
    double exp = a*bef, expinc = a*bef;
    while (bef < 1) {
        expinc = (expinc/bef/num)*(1-bef)*fmin(bef*(1+k/100.0), 1.0)*(num+1);
        num++;
        exp += expinc;
        bef = bef*(1+k/100.0); 
    }

    printf("%.7f", exp);
    return 0;
}