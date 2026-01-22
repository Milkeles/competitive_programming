#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> a(n, 0);
    int last = n;
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (cnt == (n - 1)) break;
        for (int j = i; j <= n; j += i) {
            if(a[j]) continue;
            a[j] = true;
            ++cnt;
            last = j;
        }
        cout << '\n';
    }
    cout << last;
}