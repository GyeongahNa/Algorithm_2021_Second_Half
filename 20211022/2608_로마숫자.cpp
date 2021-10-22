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

typedef vector<string>::iterator iter;

vector<int> vnum = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> vstr = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int convToInt(string& str) {

    int n = 0;
    for (int i=0; i<str.size(); i++) {
        iter it1 = find(vstr.begin(), vstr.end(), str.substr(i, 1));
        iter it2 = find(vstr.begin(), vstr.end(), str.substr(i, 2));
        int idx = (it2 != vstr.end()) ? it2-vstr.begin() : it1-vstr.begin();
        i = (it2 != vstr.end()) ? i+1 : i;
        n += vnum[idx];
    }
    return n;
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = convToInt(s1);
    int n2 = convToInt(s2);
    int sum = n1+n2;
    cout<<sum<<endl;

    int idx = 0;
    int t = 0;
    while (sum) {
        int sh = sum/vnum[idx];
        if (sh != 0) {
            for (int i=0; i<min(sh, 3); i++)
            cout << vstr[idx];
            sum-=vnum[idx]*min(sh, 3);
        }
        idx++;
    }
    return 0;
}