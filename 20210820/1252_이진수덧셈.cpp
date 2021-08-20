#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {

    string s1, s2, sm, bg;
    int over;
    vector<int> v;
    
    cin >> s1 >> s2;
    s1 = s1.substr(s1.find('1'), s1.size() - s1.find('1'));
    s2 = s2.substr(s2.find('1'), s2.size() - s2.find('1'));

    sm = (s1.size() < s2.size()) ? s1 : s2;
    bg = (s1.size() < s2.size()) ? s2 : s1;

    over = 0;
    for (int i = 0; i < sm.size(); i++) {
        v.push_back((over + sm[sm.size()-1-i] + bg[bg.size()-1-i] - 2*'0') % 2);
        over = (over + sm[sm.size()-1-i] + bg[bg.size()-1-i] - 2*'0') / 2;
    }

    for (int i = bg.size() - sm.size() - 1; i >= 0; i--) {
        v.push_back((over + bg[i] - '0') % 2);
        over = (over + bg[i] - '0') / 2;
    }

    if (over == 1)
        v.push_back(1);

    for (int i = v.size() - 1; i >= 0; i--)
        printf("%d", v[i]);
    printf("\n");
    return 0;
}