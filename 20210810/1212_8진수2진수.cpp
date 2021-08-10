#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void printBinary(char n, int i) {

    if ((i == 0) && (n == '0'))
        cout << '0';
    else if ((i == 0) && (n == '1'))
        cout << '1';
    else if ((i == 0) && (n == '2'))
        cout << "10";
    else if ((i == 0) && (n == '3'))
        cout << "11";
    else if (n == '0')
        cout << "000";
    else if (n == '1')
        cout << "001";
    else if (n == '2')
        cout << "010";
    else if (n == '3')
        cout << "011";
    else if (n == '4')
        cout << "100";
    else if (n == '5')
        cout << "101";
    else if (n == '6')
        cout << "110";
    else if (n == '7')
        cout << "111";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string oct;

    cin >> oct;
    for (int i = 0; i < oct.size(); i++) {
        printBinary(oct[i], i);
    }
    cout << endl;
    return 0;
}