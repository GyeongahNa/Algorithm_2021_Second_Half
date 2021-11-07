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
    
    while (N--) {
        int N;
        double D, A, B, F;
        scanf("%d %lf %lf %lf %lf", &N, &D, &A, &B, &F);
        printf("%d %f\n", N, D/(A+B)*F);
    }
    return 0;
}