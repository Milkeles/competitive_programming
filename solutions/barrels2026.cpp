#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,fast-math")

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int S;
    short N;
    cin >> S >> N;
    
    vector<int> barrels(N);
    int max_barrel = 0;
    for (short i = 0; i < N; ++i) {
        cin >> barrels[i];
        if (barrels[i] > max_barrel) max_barrel = barrels[i];
    }

    int base_count = 0;
    int remaining_S = S;

    if (S > 10000) {
        base_count = (S / max_barrel);
        remaining_S = S - ((base_count - 1) * max_barrel);
    }


    vector<int> dp(remaining_S + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= remaining_S; ++i) {
        for (int coin : barrels) {
            if (coin <= i && dp[i - coin] != -1) {
                if (dp[i] == -1 || dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                }
            }
        }
    }
    if (dp[remaining_S] == -1) {
        cout << base_count << endl;
    } else {
        cout << dp[remaining_S] + base_count;
    }
    
    return 0;
}