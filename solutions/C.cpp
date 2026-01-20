// Author: H. Hristov
#pragma GCC optimize("O3,avx2,unroll-loops,Ofast,fast-math,no-stack-protector")
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(1000000, INT_MAX);
    for (int i = 0; i < n; ++i) {
        int s, e, p;
        cin >> s >> e >> p;
        for (int j = s; j <= e; ++j) {
            arr[j] = min(arr[j], p);
            if (e > b) {
                arr[j] = min(arr[j], b - s);
            }
        }
    }

    ll cost = arr[a + 1];
    int last = arr[a + 1];
    for (int i = a + 1; i <= b; ++i) {
        if (arr[i] != last) {
            cost += arr[i];
            last = arr[i];
        }
    }

    cout << cost;
    return 0;
}