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
    cin >> s;
    
    vector<string> v;
    for (int i=0; i<s.size(); i++)
        v.push_back(s.substr(i));
    
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<endl;
    cout<<endl;
    
    return 0;
}