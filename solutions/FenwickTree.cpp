#pragma GCC optimize("O3,unroll-loops,avx2,Ofast,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define SIZE 100001
using namespace std;

int N;
ll tree[SIZE];

ll find(int n) {
    ll res = 0;
    while(n > 0) {
        res += tree[n];
        n -= n & (-n); // n &= (n - 1);
    }

    return res;
}

void update(int n, int val) {
    while(n <= N) {
        tree[n] += val;
        n += n & (-n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    // Always use 1-based indexing. Otherwise the update operation loops infinitely because 0 has no set bits.
    for(int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        tree[i] += num;
        int p = i + (i & -i);
        if(p <= N) {
            tree[p] += tree[i];
        }
    }

    int s, e;
    cin >> s >> e;
    for (int i = 0; i < N; ++i) {
        cout << tree[i] << ' ';
    }

    cout << '\n' << find(e + 1) - find(s) << '\n';
}
/*
Prefix sums:
O(1) find, O(n) update, O(n) space.
Fenwick trees:
O(log n) find, O(log n) update, O(n) space.
Conclusion:
If the array is static, use prefix sums.
If the array gets modified after each querry, use Fenwick trees.
If you need sum, min, max, gcd, and range updates, use segment tree.
(Learn next).
*/
