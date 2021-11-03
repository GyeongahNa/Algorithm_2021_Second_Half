#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        
        string s;
        cin >> s;
        
        int cnt = 0;
        for (int i=0; i<s.size(); i++) {
            
            if (s[i] == '(') cnt++;
            else cnt--;
            if (cnt < 0) {
                printf("NO\n");
                break;
            }
        }
        if (cnt == 0) printf("YES\n");
        else if (cnt > 0) printf("NO\n");
    }
    
    return 0;
}