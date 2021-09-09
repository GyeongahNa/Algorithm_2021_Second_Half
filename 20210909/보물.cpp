#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

vector<int> getIdxVec(const vector<int>& v) {

    vector<int> vSorted = v;
    sort(vSorted.begin(), vSorted.end());

    vector<int> vIdx;
    for (int i=0; i < v.size(); i++) {
        int idx = find(vSorted.begin(), vSorted.end(), v[i]) - vSorted.begin();
        vSorted[idx]=-1;
        vIdx.push_back(idx);
    }

    return vIdx;
}

int main() {

    int N;
    scanf("%d", &N);

    vector<int> vA(N), vB(N);
    for (int i=0; i<N; i++)
        scanf("%d", &vA[i]);
    for (int i=0; i<N; i++)
        scanf("%d", &vB[i]);
    
    vector<int> vAIdx = getIdxVec(vA);
    vector<int> vBIdx = getIdxVec(vB);

    int sum = 0;
    for (int i=0; i<N; i++) {
        int idx = find(vAIdx.begin(), vAIdx.end(), (N-1)-vBIdx[i])-vAIdx.begin();
        sum += vA[idx]*vB[i]; 
    }

    printf("%d\n", sum);
    return 0;
}