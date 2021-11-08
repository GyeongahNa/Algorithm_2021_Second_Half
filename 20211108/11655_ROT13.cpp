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

string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {
    
    string s;
    getline(cin, s);
    
    for (int i=0; i<s.size(); i++) {
        
        char c;
        if (s[i] >= 'A' && 'Z' >= s[i]) {
            int idx = alpha.find(s[i]+32);
            c = alpha[(idx+13)%26]-32;
        }
        else if (s[i] >= 'a' && 'z' >= s[i]) {
            int idx = alpha.find(s[i]);
            c = alpha[(idx+13)%26];
        }
        else c = s[i];
        printf("%c", c);
    }
    
    return 0;
}