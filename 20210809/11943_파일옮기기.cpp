#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int A, B, C, D;

    cin >> A >> B >> C >> D;
    cout << min(A + D, B + C) << endl;
    return 0;
}