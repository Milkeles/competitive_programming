// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll a, b, cnt = 0;
    cin >> a >> b;
    a = 9 * (a / 9 + 1);

    ll a2 = a * 9LL;

    ll num1 = a, num2 = a2, sum1 = 0, sum2 = 0;

    while (num1 > 0) {
        sum1 += num1 % 10; num1 /= 10;
        sum2 += num2 % 10; num2 /= 10;
    }

    if (num2 > 0) sum2 += num2;

    do {
        if (sum1 == sum2) ++cnt;

        if (a % 10 == 0) sum1 += 9;
        else {
            ll t = a / 10;
            while (t % 10 == 9) {
                sum1 -= 9;
                t /= 10;
            }
        }

        if (a2 % 10 == 9) sum2 -= 9;
        if (a2 % 100 < 19) sum2 += 9;

        else {
            ll t = a2 / 100;
            while (t % 10 == 9) { 
                sum2 -= 9;
                t /= 10;
            }
        }
        a  += 9;
        a2 += 81;
    } while (a <= b);
    cout << cnt;
    return 0;
}
// Priznak za delimost na 9 + razlikata mezdu 9N i 9(N+9) = 81.
// + ne presmqtame sumata nanowo wseki put.