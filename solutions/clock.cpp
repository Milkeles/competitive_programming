// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short h, m;
    cin >> h >> m;
    short t = (60*h - 11*m + 720) % 720;
    cout << t*2/ 22;
}