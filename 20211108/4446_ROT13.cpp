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

map<char, char> setmap() {
    
    map<char, char> m;
    
    vector<char> v = {'a', 'i', 'y', 'e', 'o', 'u'};
    vector<char> c = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 
                      'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
    
    for (int i=0; i<v.size(); i++) 
        m.insert({v[i], v[(i+3)%6]});
    
    for (int i=0; i<c.size(); i++)
        m.insert({c[i], c[(i+10)%20]});
    
    return m;
}

int main() {
    
    string s;
    map<char, char> m = setmap();

    while (getline(cin, s)) {

        char c;
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'A' && 'Z' >= s[i]) c = m[s[i]+32]-32;
            else if (s[i] >= 'a' && 'z' >= s[i]) c = m[s[i]];
            else c = s[i];
            printf("%c", c);
        }
        printf("\n");
    }
    
    return 0;
}