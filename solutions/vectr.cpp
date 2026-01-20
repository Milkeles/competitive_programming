// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short T;
    cin >> T;
    
    while(T--) {
        int x1, y1, x2, y2, a, b;
        cin >> x1 >> y1 >> x2 >> y2 >> a >> b;

        // -10^6 <= x1,x2,y1,y2 <= 10^6
        // => lenX, lenY <= 2 * 10^6
        int lenX = abs(x2 - x1);
        int lenY = abs(y2 - y1);

        // a <= 10^6, lenX <= 2 * 10^6
        // but a - lenX > 2*10 ^ 6?? HOW?!
        ll remA = (a - lenX) + 1;
        ll remB = (b - lenY) + 1;
        /*
        How does substracting from a number that is at most 10^6
        another number that is at most 2 * 10^6
        result in a number larger than 10^6???
        */

        // Nevermind. Math is mathing. Just missing overflow.

        ll res;
        if (remA < 0 || remB < 0) {
            res = 0;
        } else {
            // Note to self: Be careful with overflows.
            // doing (ll)(remA * remB) wouldn't solve it, it would've already overflown by the time it converts.
            // Overflow happens during multiplication. int * int.
            res = (ll)remA * (ll)remB;
        }

        cout << res << '\n';
    }
    
    return 0;
}