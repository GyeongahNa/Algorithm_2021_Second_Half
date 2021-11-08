#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
#include <map>
using namespace std;

int main() {
    
    string s;
    while (getline(cin, s)) {
        
        vector<int> cnt(4, 0);
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'a' && 'z' >= s[i]) cnt[0]++;
            else if (s[i] >= 'A' && 'Z' >= s[i]) cnt[1]++;
            else if (s[i] >= '0' && '9' >= s[i]) cnt[2]++;
            else cnt[3]++;
        }
        
        for (int i=0; i<4; i++)
            cout<<cnt[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}