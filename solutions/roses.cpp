// Национална олимпиада - Областен кръг > C > 2011 > roses
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> grid(M, vector<int>(N));
    int total = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            total += grid[i][j];
        }

    vector<vector<int>> rowSum(M, vector<int>(N - K + 1));
    for (int i = 0; i < M; i++) {
        int s = 0;
        for (int j = 0; j < K; j++) s += grid[i][j];
        rowSum[i][0] = s;
        for (int j = 1; j <= N - K; j++) {
            s += grid[i][j + K - 1] - grid[i][j - 1];
            rowSum[i][j] = s;
        }
    }

    int maxSum = 0;
    for (int j = 0; j < N - K + 1; j++) {
        int s = 0;
        for (int i = 0; i < K; i++) s += rowSum[i][j];
        maxSum = max(maxSum, s);
        for (int i = 1; i <= M - K; i++) {
            s += rowSum[i + K - 1][j] - rowSum[i - 1][j];
            maxSum = max(maxSum, s);
        }
    }

    cout << total - maxSum;
}