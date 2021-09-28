#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using ii = pair<int, int>;

int findStart(const vector<ii>& v, int start) {

    for (int i=0; i<v.size(); i++) {
        if (v[i].first == start)
            return i;
    }
    return -1;
}

void getInput(vector<ii>& v, int N) {

    for (int i=0; i<N; i++) {
        int s, e;
        scanf("%d %d", &s, &e);

        int idx = findStart(v, s);
        if (idx == -1) v.push_back({s, e});
        else if (idx != -1 && v[idx].second > e)
            v[idx].second = e;
    }
    sort(v.begin(), v.end());
}

int binarySearch(const vector<ii>& v, int i, int num) {

    int first = i+1;
    int last = (int)v.size()-1;
    int mid;
    int re = (int)v.size();

    while (first <= last) {
        
        mid = (first+last)/2;
        if (num > v[mid].first) first = mid+1;
        else {
            re = mid;
            last = mid-1;
        }
    }
    return re;
}

int main() {

    int N;
    scanf("%d", &N);

    vector<ii> v;
    getInput(v, N);

    int size = (int)v.size();
    int dp[size+1];
    dp[size] = 0;

    for (int i=size-1; i>=0; i--) {
        int idx = binarySearch(v, i, v[i].second);
        dp[i] = max(1+dp[idx], dp[i+1]);
    }
    printf("%d", dp[0]);
    return 0;
}   