#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

bool arr[1002];

void check(const string& s, int N) {
    
    memset(arr, false, sizeof(arr));
    
    string num = "";
    int st = -1, ed = -1;
    for (int i=0; i<s.size(); i++) {
        if (s[i] != ',' && s[i] != '-') num += s[i];
        if (s[i] == '-')  {
            if (num.size() > 5) num = "1001";
            st = stoi(num);
            num = "";
        }
        if (s[i] == ',') {
            if (num.size() > 5) num = "1001";
            ed = min(stoi(num), N);
            if (st == -1) st = stoi(num);
            for (int j=st; j<=ed; j++) arr[j] = true;
            st = -1; ed = -1; num = "";
        }
    }
}

int main() {
    
    int N;
    scanf("%d", &N);
    
    while (N > 0) {
        
        string s;
        cin >> s;
        s += ',';
        check(s, N);
        
        int sum = 0;
        for (int i=1; i<=N; i++)
            if (arr[i]) sum++;
        printf("%d\n", sum);
        
        scanf("%d", &N);
    }
    return 0;
}