#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    char last = s.back(); int sum = 0;
    for (char & c : s) {
        sum += c - '0';
    }
    cout << !((last - '0') & 1) << ' ' << (sum % 3 == 0) << ' ' << ((last - '0') % 5 == 0);  
}
