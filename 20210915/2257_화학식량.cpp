#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
using iii = tuple<int, int, int>;

void checkNextAdd(const string& s, int& i, int& addTo) {

    if (i < s.size()-1 && s[i+1] >= '2' && '9' >= s[i+1])
        addTo+=s[i+1]-'0';
    else addTo++;
}

int findCloseBracket(const string& s, int& i) {

    int idx = s.find(')', i+1);
    while (idx != string::npos) {
        int cntLeft = count(s.begin()+i+1, s.begin()+idx, '(');
        int cntRight = count(s.begin()+i+1, s.begin()+idx, ')');
        if (cntLeft == cntRight)
            break;
        idx = s.find(')', idx+1);
    }
    return idx;
}

iii getStoichiometry(const string &s) {

    int cntC = 0, cntH = 0, cntO = 0;

    int i;
    for (i=0; i<s.size(); i++) {
        
        if(s[i] >= '2' && '9' >= s[i]) continue;
        else if (s[i] == 'H') checkNextAdd(s, i, cntH);
        else if (s[i] == 'C') checkNextAdd(s, i, cntC);
        else if (s[i] == 'O') checkNextAdd(s, i, cntO);
        else if (s[i] == '(') {

            int idx = findCloseBracket(s, i);
            string sUnit = s.substr(i+1, idx-i-1);
            iii t = getStoichiometry(sUnit);

            i=idx;
            int mult = 1;
            if (i < s.size()-1 && s[i+1] >= '2' && '9' >= s[i+1])
                mult = s[i+1]-'0';

            cntH+=get<0>(t)*mult;
            cntC+=get<1>(t)*mult;
            cntO+=get<2>(t)*mult;
        }
    }
    return make_tuple(cntH, cntC, cntO);
}

int main() {

    string s;
    cin >> s;
    iii re = getStoichiometry(s);

    int cntH = get<0>(re);
    int cntC = get<1>(re);
    int cntO = get<2>(re);
    printf("%d", cntH+cntC*12+cntO*16);
    return 0;   
}

// iii cntElement(const string &s) {

//     int cntC = 0, cntH = 0, cntO = 0;

//     for (int i=0; i<s.size(); i++) {
        
//         if (s[i] != 'C' && s[i] != 'H' && s[i] != 'O') continue;
//         else if (s[i] == 'C') {
//             if (i < s.size() && s[i+1] >= '2' && '9' >= s[i+1])
//                 cntC+=s[i+1]-'0';
//             else cntC++;
//         }
//         else if (s[i] == 'H') {
//             if (i < s.size() && s[i+1] >= '2' && '9' >= s[i+1])
//                 cntH+=s[i+1]-'0';
//             else cntH++;
//         }
//         else {
//             if (i < s.size() && s[i+1] >= '2' && '9' >= s[i+1])
//                 cntO+=s[i+1]-'0';
//             else cntO++;
//         }       
//     }
//     return make_tuple(cntC, cntH, cntO);
// }


// int main() {

//     string s;
//     cin >> s;

//     int i = 0;
//     int cntC = 0, cntH = 0, cntO = 0;
//     while (i < s.size()) {
        
//         string sUnit = "";
//         if (s[i] == '(') {
//             int next = s.find(')', i+1);
//             sUnit = s.substr(i+1, next-i-1);
//             i = next+1;
//         }
//         else if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
//             sUnit = s.substr(i, 1);
//             i++;
//         }

//         int mult = 1;
//         if (i < s.size() && s[i] >= '2' && '9' >= s[i]) {
//             mult = s[i]-'0';
//             i++;
//         }

//         cntC+=get<0>(cntElement(sUnit))*mult;
//         cntH+=get<1>(cntElement(sUnit))*mult;
//         cntO+=get<2>(cntElement(sUnit))*mult;
//     }
//     printf("%d\n", cntH+cntC*12+cntO*16);
//     return 0;
// }