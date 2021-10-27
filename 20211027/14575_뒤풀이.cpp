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

vector<int> vs, ve;
int N, T;
int maxs, maxe, mint, maxt;

int binarySearch() {

    int first = maxs;
    int last = maxe;
    int re = -1;
    int mid;

    while (first <= last) {
        
        mid = (first+last)/2;

        maxt = 0;
        for (int i=0; i<ve.size(); i++)
            maxt += min(ve[i], mid);
        
        if (T >= mint && maxt >= T) {
            re = mid;
            last = mid-1;
        }
        else first = mid+1;
    }
    return re;
}

int main() {

    scanf("%d %d", &N, &T);

    maxs = 0; maxe = 0; mint = 0;
    for (int i=0; i<N; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        vs.push_back(s);
        ve.push_back(e);
        maxs = max(vs[i], maxs);
        maxe = max(ve[i], maxe);
        mint += s;
    }

    printf("%d", binarySearch());
    return 0;
}