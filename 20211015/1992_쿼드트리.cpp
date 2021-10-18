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

char map[64][64];

void solve(int row, int col, int size) {

    for (int r=row; r<row+size; r++) {
        for (int c=col; c<col+size; c++) {
            if (map[row][col] != map[r][c]) {

                printf("(");
                solve(row, col, size/2);
                solve(row, col+size/2, size/2);
                solve(row+size/2, col, size/2);
                solve(row+size/2, col+size/2, size/2);
                printf(")");
                return ;
            }
        }
    }
    printf("%c", map[row][col]);
    return ;
}

int main() {

    int N;
    scanf("%d", &N);
    memset(map, '0', sizeof(map));

    for (int i=0; i<N*N; i++)
        scanf(" %c", &map[i/N][i%N]);

    solve(0, 0, N);
    return 0;
}