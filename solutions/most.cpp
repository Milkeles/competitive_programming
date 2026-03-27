// Национална олимпиада - Общински кръг > C > 2023 >> most
// Author: H. Hristov
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    ll a, b, k;
    cin >> a >> b >> k;
    
    ll p1 = a + (k - a % k);
    ll p2 = b - b % k;
    
    if (b - a < k) {
        cout << ((b - a + 1) >> 1);
        return 0;
    }
    
    ll l1 = (((p1 - 1) - a + 1) >> 1);
    ll r1 = ((b - (p2 + 1) + 1) >> 1);
    ll br = (p2 - p1) / k + 1;
    
    k--;
    cout << l1 + (br - 1) * (k / 2) + br + r1;
}