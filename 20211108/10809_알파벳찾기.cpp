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

int check[26];

int main() {
    
    string s;
    cin >> s;
    memset(check, -1, sizeof(check));
    
    for (int i=0; i<s.size(); i++) {
        if (check[s[i]-'a'] != -1) continue;
        check[s[i]-'a'] = i;
    }
    
    for (int i=0; i<26; i++)
        cout<<check[i]<<" ";
    return 0;
}