#include <bits/stdc++.h>
using namespace std;

int n;
int sum[3];
bool solve(vector<vector<short>> & arr, int gr, int & cnt) {
    int gr1 = (gr + 1) % 3, gr2 = (gr + 2) % 3;

    for(int i = 0; i < arr[gr].size(); ++i) {
        sum[gr] -= arr[gr][i];
        sum[gr1] += arr[gr][i];
        sum[gr2] += arr[gr][i];
        if(sum[0] == sum[1] && sum[1] == sum[2]) return cnt;
        sum[gr] += arr[gr][i];
        sum[gr1] -= arr[gr][i];
        sum[gr2] -= arr[gr][i];
    }

    cnt = 1 + min(solve(arr, gr1, cnt), solve(arr, gr2, cnt));

    return cnt;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short n, cnt, total = 0;
    cin >> n;
    vector<vector<short>> arr(3);
    for(int i = 0; i < n; ++i) {
        short a, b;
        cin >> a >> b;
        total += b;
        arr[a-1].push_back(b);
        sum[a-1] += b;
    }

    if (total % 3 != 0) {
        cout << -1;
        return 0;
    }

    int res = 1;
    solve(arr, 0, res);

    cout << res;
    return 0;
}