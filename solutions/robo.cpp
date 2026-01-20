#pragma GCC optimize("O3,unroll-loops,Ofast,avx2")
#include <bits/stdc++.h>

using namespace std;


int binarySearch(int l, int r, int & T, vector<int> & A, vector<int> & B, vector<int> & C, vector<int> & D) {
    int mid = l + (r - l)/2;

    int produced = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > mid) continue;
        produced += (mid - A[i]) / B[i];
    }

    int painted = 0;
    for (int i = 0; i < B.size(); ++i) {
        if (C[i] > (T - mid)) continue;
        painted += ((T - mid) - C[i]) / D[i];
    }

    if (painted == produced) {
        return mid;
    } else if (painted > produced) {
        return binarySearch(mid + 1, r, T, A, B, C, D);
    } else {
        return binarySearch(l, mid - 1, T, A, B, C, D);
    }

    return l;
}
int main() {
    long long T;
    cin >> T;

    short n, m;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i] >> B[i];
    cin >> m;

    vector<int> C(m), D(m);
    for (int i = 0; i < m; ++i) cin >> C[i] >> D[i];

    cout << binarySearch(1, T, T, A, B, C, D);
}