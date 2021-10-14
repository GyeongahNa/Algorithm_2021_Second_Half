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

int tree[26][2];

void preorder(int root) {

    printf("%c", root+'A');
    if (tree[root][0] != -1) preorder(tree[root][0]);
    if (tree[root][1] != -1) preorder(tree[root][1]);
    return ;
}

void inorder(int root) {

    if (tree[root][0] != -1) inorder(tree[root][0]);
    printf("%c", root+'A');
    if (tree[root][1] != -1) inorder(tree[root][1]);
    return ;
}

void postorder(int root) {

    if (tree[root][0] != -1) postorder(tree[root][0]);
    if (tree[root][1] != -1) postorder(tree[root][1]);
    printf("%c", root+'A');
    return ;
}

void solve(int root) {
    
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return ;
}

int main() {

    int N;
    scanf("%d", &N);
    memset(tree, -1, sizeof(tree));

    for (int i=0; i<N; i++) {
        char n, l, r;
        scanf(" %c %c %c", &n, &l, &r);
        if (l != '.') tree[n-'A'][0] = l-'A';
        if (r != '.') tree[n-'A'][1] = r-'A';
    }
    solve(0);
    return 0;
}