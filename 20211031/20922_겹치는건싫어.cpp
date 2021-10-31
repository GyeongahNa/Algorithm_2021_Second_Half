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

bool check(const vector<int>& v, vector<int>& cnt, int mid, int K) {
   
    for (int i=0; i<=(int)v.size()-mid; i++) {

        if (i == 0) {
            for (int i=0; i<mid; i++)
                cnt[v[i]]++;
        }
        else {
            cnt[v[i-1]]--;
            cnt[v[i+(mid-1)]]++;
        }
        int maxcnt = *max_element(cnt.begin(), cnt.end());
        if (maxcnt <= K) return true;
    }
    return false;
}

int binarySearch(const vector<int>& v, int K) {

    int first = K;
    int last = (int)v.size();
    int mid;
    int re = K;

    while (first <= last) {

        mid = (first+last)/2;

        vector<int> cnt(100001, 0);
        if (check(v, cnt, mid, K)) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return re;
}

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    printf("%d", binarySearch(v, K));
    return 0;
}