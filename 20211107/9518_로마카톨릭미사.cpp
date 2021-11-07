#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

int R, S;
int map[50][50];
bool check[50][50][50][50];

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void getSeat() {

    int maxn = 0, seati = -1, seatj = -1;
    for (int i=0; i<R; i++) {
        for (int j=0; j<S; j++) {
            if (map[i][j] == 1) continue;
            
            int n = 0;
            for (int k=0; k<8; k++) {
                int newy = i+dy[k], newx = j+dx[k];
                if (newy < 0 || newy > R-1 || newx < 0 || newx > S-1) continue;
                if (map[newy][newx] == 0) continue;
                n++;
            }

            if (maxn < n) {
                maxn = n; seati = i; seatj = j;
            }
        }
    }
    if (seati != -1 && seatj != -1) map[seati][seatj] = 1;
}

int getcnt() {
    
    int sum = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<S; j++) {
            if (map[i][j] == 0) continue;
            
            for (int k=0; k<8; k++) {
                int newy = i+dy[k], newx = j+dx[k];
                if (newy < 0 || newy > R-1 || newx < 0 || newx > S-1) continue;
                if (map[newy][newx] == 0) continue;
                if (check[i][j][newy][newx]) continue;
                
                check[i][j][newy][newx] = true;
                check[newy][newx][i][j] = true;
                sum++;
            }
        }
    }
    return sum;
}

int main() {
    
    scanf("%d %d", &R, &S);
    memset(map, 0, sizeof(map));
    memset(check, false, sizeof(check));
    
    for (int i=0; i<R; i++) {
        char line[51];
        scanf("%s", line);
        for (int j=0; j<S; j++)
            map[i][j] = (line[j] == '.') ? 0 : 1;
    }
    
    getSeat();
    printf("%d", getcnt());
    return 0;
}