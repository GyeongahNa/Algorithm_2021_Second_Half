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

bool check(const vector<int>& v, int mid, int K) {

    int num =0;
    for (int i=0; i<=v.size()-mid; i++) {
        if (i == 0) {
            for (int j=0; j<mid; j++)
                if (v[j] == 1) num++;
        }
        else {
            if (v[i-1] == 1) num--;
            if (v[i+(mid-1)] == 1) num++;
        }
        if (num >= K) return true;
    }
    return false;
}

int binarySearch(const vector<int>& v, int N, int K) {

    int first = 1;
    int last = N;
    int re = -1;
    int mid;

    while (first <= last) {

        mid = (first+last)/2;
        if (check(v, mid, K)) {
            re = mid;
            last = mid-1;
        }
        else first = mid+1;
    }
    return re;
}

int main() {

    int N, K;
    scanf("%d %d", &N, &K);
    
    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);
    
    printf("%d", binarySearch(v, N, K));
    return 0;
}