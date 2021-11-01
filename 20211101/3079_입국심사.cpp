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

long long binarySearch(const vector<long long>& v, long long maxTime, long long M) {

    long long first = 1;
    long long last = maxTime;
    long long re = maxTime;
    long long mid, num, time;

    while (first <= last) {

        mid = (first+last)/2;

        num = 0;
        for (long long i=0; i<v.size(); i++)
            num += mid/v[i];
        
        if (num >= M) {
            re = mid;
            last = mid-1;
        }
        else first = mid+1;        
    }
    return re;
}

int main() {

    long long N, M;
    scanf("%lld %lld", &N, &M);

    vector<long long> v(N);
    long long minval = 1000000001;
    for (long long i=0; i<N; i++) {
        scanf("%lld", &v[i]);
        minval = min(minval, v[i]);
    }
    
    printf("%lld", binarySearch(v, minval*M, M));
    return 0;
}