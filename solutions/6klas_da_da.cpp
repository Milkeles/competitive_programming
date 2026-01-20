// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;
#define ll long long

string n;
short k;
ll dp[20][20][2][2];

ll solve(int pos, int cnt, int tight, int started) {
    if (pos == n.size()) return cnt;

    if (dp[pos][cnt][tight][started] != -1) return dp[pos][cnt][tight][started];

    int limit = tight ? (n[pos] - '0') : 9;

    ll ans = 0;

    for (int d = 0; d <= limit; ++d) {
        int newTight = (tight && d == limit) ? 1 : 0;
        int newCnt = cnt;
        int newStarted = (started || d != 0);
        if (newStarted && d == k) {
            ++newCnt;
        }
        ans += solve(pos + 1, newCnt, newTight, newStarted);
    }

    dp[pos][cnt][tight][started] = ans;
    return dp[pos][cnt][tight][started];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;

    int len = n.size();
    memset(dp, -1, sizeof(dp));

    ll res = solve(0, 0, 1, 0);
    if (k == 0) ++res;

    cout << res;

    return 0;
}

// Задачи > Национална олимпиада - Областен кръг > D > 2015

/*
// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

// [pos][cnt][tight][started]
ll dp[20][20][2][2];
short k, x;

int solve(string num, int pos, int cnt, int tight, int started) {
    if (pos == num.size()) return cnt;
    if (dp[pos][cnt][tight][started] != -1) return dp[pos][cnt][tight][started];

    short limit = tight ? (num[pos] - '0') : 9;

    ll res = 0;

    int curCnt = 0;

    for (short d = 0; d <= limit; ++d) {
        int newCnt = cnt;
        
        int newTight = (tight && d == limit) ? 1 : 0;
        int newStarted = (started || d != 0);
        if (newStarted && d == k) {
            ++newCnt;
        }
        res += solve(num, pos + 1, newCnt, newTight, newStarted);
    }

    dp[pos][cnt][tight][started] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string A, B;
    cin >> A >> B >> k >> x;
    // [A, B] = [0, B] - [0, A];
    memset(dp, -1, sizeof(dp));
    ll resA = solve(A, 0, 0, 1, 0);
    memset(dp, -1, sizeof(dp));
    ll resB = solve(B, 0, 0, 1, 0);
    if (k == 0) {
        ++resA; ++resB;
    }

    cout << resB - resA;
    return 0;
}*/