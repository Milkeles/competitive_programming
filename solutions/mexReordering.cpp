// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    short t;
    cin >> t;
    while(t--) {
        short n, cnt0 = 0, cnt1 = 0, num;
        cin >> n;
        while(n--) {
            cin >> num;
            if (num == 0) ++cnt0;
            else if (num == 1) ++cnt1;
        }

        if (cnt0 == 0 || (cnt0 > 1 && cnt1 == 0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}