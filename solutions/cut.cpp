#include <iostream>

using namespace std;

int main () {
    short m, n;
    cin >> m >> n;

    cout << ((!(m & 1) || !(n & 1)) ? 0 : min(n, m));
}