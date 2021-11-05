#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;

int main() {
    
    int a;
    scanf("%d", &a);
    while (a) {
        
        int nLeaves = 1;
        while (a--) {
            int splfactor, cut;
            scanf("%d %d", &splfactor, &cut);
            nLeaves = nLeaves*splfactor-cut;
        }
        printf("%d\n", nLeaves);
        scanf("%d", &a);
    }
    return 0;
}