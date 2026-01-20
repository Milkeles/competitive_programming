#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    // find min, mid, max using only 2-element min/max
    ll x = min(a, min(b, c));
    ll z = max(a, max(b, c));
    ll y = a + b + c - x - z;

    // cost to bring smaller genres up to largest
    ll cost0 = 2*(z - x) + 2*(z - y);

    ll res;
    if (cost0 > n) {
        // not enough money to reach z, fallback to average
        res = (a + b + c + n)/3;
    } else {
        // extra evenings after equalizing
        ll rem = n - cost0;
        res = z + rem / 6;  // each extra evening costs 6 leva
    }

    cout << res - 1<< "\n";
}
