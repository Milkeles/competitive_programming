// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,avx2,Ofast")
#define ll long long;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int num = 0, curMin = INT_MAX, res = 0;

        for(int i = 0; i < N; ++i) {
            cin >> num;
            curMin = min(num, curMin);
            res = max(num - curMin, res);
        }

        cout << res << '\n';
    }
    return 0;
}