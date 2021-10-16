
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

int N, C, re;
vector<int> vh;

bool check(int mid) {

    int cnt = 1;
    int prev = vh[0];

    for (int i=1; i<N; i++) {
        if (vh[i]-prev >= mid) {
            cnt++;
            prev = vh[i];
        }
    }
    if (cnt >= C) return true;
    return false;
}

void binarySearch() {

    int first = 1;
    int last = vh[N-1]-vh[0];
    int mid;
    
    re = 1;
    while (first <= last) {
        mid = (first+last)/2;
        if (check(mid)) {
            re = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
}

int main() {

    scanf("%d %d", &N, &C);
    for (int i=0; i<N; i++) {
        int h;
        scanf("%d", &h);
        vh.push_back(h);
    }
    sort(vh.begin(), vh.end());
    binarySearch();
    printf("%d", re);
    return 0;
}