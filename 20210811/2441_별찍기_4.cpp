#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N;

    cin >> N;
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= N - i; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}