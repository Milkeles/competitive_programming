#include <iostream>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short t;
    cin >> t;
    while(t--) {
        ll i, j;
        cin >> i >> j;
        ll res = ((i + j - 2) * (i + j - 1)) >> 1;
        if ((i + j) & 1) res += i;
        else res += j;
        
        cout << res << '\n';
    }

    return 0;
}