#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>
using namespace std;

vector<vector<int>> opFlip(const vector<vector<int>>& map, int op) {

    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> re(h, vector<int>(w, 0));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (op == 1) re[i][j] = map[h-1-i][j];
            else re[i][j] = map[i][w-1-j];
        }
    }
    return re;
}

vector<vector<int>> opRotate(const vector<vector<int>>& map, int op) {

    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> re(w, vector<int>(h, 0));

    for (int i=0; i<w; i++) {
        for (int j=0; j<h; j++) {
            if (op == 3) re[i][j] = map[h-j-1][i];
            if (op == 4) re[i][j] = map[j][w-i-1];
        }
    }
    return re;
}

vector<vector<int>> opSplit1(const vector<vector<int>>& map) {

    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> re(h, vector<int>(w, 0));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (i>=0 && i<h/2 && j>=0 && j<w/2) re[i][j+w/2] = map[i][j];
            if (i>=0 && i<h/2 && j>=w/2 && j<w) re[i+h/2][j] = map[i][j];
            if (i>=h/2 && i<h && j>=w/2 && j<w) re[i][j-w/2] = map[i][j];
            if (i>=h/2 && i<h && j>=0 && j<w/2) re[i-h/2][j] = map[i][j];
        }
    }
    return re;
}

vector<vector<int>> opSplit2(const vector<vector<int>>& map) {

    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> re(h, vector<int>(w, 0));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (i>=0 && i<h/2 && j>=0 && j<w/2) re[i+h/2][j] = map[i][j];
            if (i>=h/2 && i<h && j>=0 && j<w/2) re[i][j+w/2] = map[i][j];
            if (i>=h/2 && i<h && j>=w/2 && j<w) re[i-h/2][j] = map[i][j];
            if (i>=0 && i<h/2 && j>=w/2 && j<w) re[i][j-w/2] = map[i][j];
        }
    }
    return re;
}

int main() {

    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);

    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf("%d", &map[i][j]);
    }

    vector<int> op(R);
    for (int i=0; i<R; i++)
        scanf("%d", &op[i]);

    vector<vector<int>> re = map;
    for (int i=0; i<R; i++) {
        if (op[i] == 1) re = opFlip(re, op[i]);
        else if (op[i] == 2) re = opFlip(re, op[i]);
        else if (op[i] == 3) re = opRotate(re, op[i]);
        else if (op[i] == 4) re = opRotate(re, op[i]);
        else if (op[i] == 5) re = opSplit1(re);
        else re = opSplit2(re);
    }

    for (int i=0; i<re.size(); i++) {
        for (int j=0; j<re[0].size(); j++)
            printf("%d ", re[i][j]);
        printf("\n");
    }
    return 0;
}