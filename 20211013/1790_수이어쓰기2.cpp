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

    int N, K;
    scanf("%d %d", &N, &K);

    long long n, idx = 0;
    while ((n = 9*(long long)pow(10, idx)*(idx+1)) <= K) {
        K-=n;
        idx++;
    }
    long long num = (long long)pow(10, idx)+(K+idx)/(idx+1)-1;
    if (num > N) printf("-1");
    else printf("%c",to_string(num)[(K+idx)%(idx+1)]);
    return 0;
}