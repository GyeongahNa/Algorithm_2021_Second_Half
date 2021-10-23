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

int main() {

    int k;
    scanf("%d", &k);

    int i = 1;
    int n = pow(2, i);
    string s = "";
    while (k-n+1 >= 0) {
        s = ((((k-n+1)%n)/(n/2)==0) ?  '4' : '7')+s;
        i++;
        n*=2;
    }
    
    printf("%s", s.c_str());
    return 0;
}