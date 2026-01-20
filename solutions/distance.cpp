#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short x, n;
    int dist1 = 0, dist2 = 0;

    cin >> x >> n;
    while(n--) {
        short v1, v2, t1, t2;
        cin >> v1 >> t1 >> v2 >> t2;
        if (v1 == v2 && t1 == t2) continue;
        dist1 += v1 * t1;
        dist2 += v2 * t2;
    }

    int dif = abs(dist1 - dist2) % x;
    cout << min(dif, x - dif);
}