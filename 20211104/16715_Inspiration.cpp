#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int main() {
    
    int N;
    scanf("%d", &N);
    
    int base = N, maxsum = 0, maxbase = 0;
    while (base > 1) {
        int num = N, sum = 0;
        while (num) {
            sum += num%base;
            num /= base;
        }
        if (sum >= maxsum) {
            maxbase = base;
            maxsum = sum;
        }
        base--;
    }

    printf("%d %d", maxsum, maxbase);
    return 0;
}