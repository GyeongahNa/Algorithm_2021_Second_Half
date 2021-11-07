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

int cnt[26];

int main() {
    
    string s;
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    
    for (int i=0; i<s.size(); i++)
        cnt[s[i]-'a']++;
    
    for (int i=0; i<26; i++)
        cout<<cnt[i]<<" ";
    return 0;
}