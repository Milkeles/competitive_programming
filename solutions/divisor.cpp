#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include "stdio.h"
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = b - a + 1;
    for (int n = a; n <= b; ++n) {
        for (int q = 1; q * (q + 1) < n; ++q) {
            int d = n / q - 1;
            if (d <= 1 || d == n-1) continue;
            if (n / d == n % d) ++cnt;
        }
    }

    printf("%d", cnt);
}