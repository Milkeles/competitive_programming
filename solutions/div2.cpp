#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "142040789421984172894879214789124789124789128749127894128974127894128974127894789";
    int r = 0;
    int a = 0;
    for (char & c : s) {
        r = (3 * r + c - '0') % 7;
        a += c - '0';
        a = (a * 10)%1000000000000000;
    }

    cout << r << '\n';
    cout << a % 7 << '\n';
    if (r == 0) cout << "Deli se\n";
    else cout << "Ne se deli\n";

    return 0;
}