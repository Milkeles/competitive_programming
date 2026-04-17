// Национална олимпиада - Национален кръг > D > 2026 > divs
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define ull unsigned long long
#define pb push_back
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> spf(MAXN + 1);
    for(int i = 1; i <= MAXN; ++i) spf[i] = i;

    for (int i = 2; i * i <= MAXN; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j+=i) {
                if (spf[j]==j) spf[j] = i;
            }
        }
    }

    int q, n;
    cin >> q;
    while(q--) {
        cin >> n;
        int l = -1, k = 0;
        while(n > 1) {
            int p = spf[n];
            if (p != l) {
                ++k;
                l = p;
            }
            n /= p;
        }
        cout << (1 << k) << ' ';
    }
    return 0;
}
/*
3
4 3 200
*/