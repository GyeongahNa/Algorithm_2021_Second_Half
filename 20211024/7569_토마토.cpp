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

int N, M, H, day = -1;
int map[100][100][100];
bool check[100][100][100];

vector<int> dh = {0, 0, 0, 0, -1, 1};
vector<int> dy = {0, -1, 0, 1, 0, 0};
vector<int> dx = {-1, 0, 1, 0, 0, 0};

queue<int> q;

void bfs() {

    while (!q.empty()) {
        int qs = q.size();
        day++;
        while (qs--) {

            int front = q.front();
            int h = front/10000;
            int y = front%10000/100;
            int x = front%10000%100;
            q.pop();

            for (int n=0; n<6; n++) {
                if (h+dh[n] < 0 || h+dh[n] > H-1) continue;
                if (y+dy[n] < 0 || y+dy[n] > N-1) continue;
                if (x+dx[n] < 0 || x+dx[n] > M-1) continue;
                if (check[h+dh[n]][y+dy[n]][x+dx[n]]) continue;
                if (map[h+dh[n]][y+dy[n]][x+dx[n]] != 0) continue;
                q.push((h+dh[n])*10000+(y+dy[n])*100+(x+dx[n]));
                check[h+dh[n]][y+dy[n]][x+dx[n]] = true;
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &M, &N, &H);
    memset(check, false, sizeof(check));

    for (int n=0; n<M*N*H; n++) {
        int i = n/(M*N), j = n%(M*N)/M, k = n%(M*N)%M;
        scanf("%d", &map[i][j][k]);
        if (map[i][j][k] != 1) continue;
        check[i][j][k] = true;
        q.push(i*10000+j*100+k);
    }

    bfs();

    for (int i=0; i<M*N*H; i++) {
        if (map[i/(M*N)][i%(M*N)/M][i%(M*N)%M] != 0) continue;
        if (check[i/(M*N)][i%(M*N)/M][i%(M*N)%M]) continue;
        printf("-1");
        return 0;
    }
    printf("%d", day);
    return 0;
}