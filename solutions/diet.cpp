#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, cutCnt = 0;
    cin >> a >> b >> c;
    int total = a + b * 2 + c * 3;
    int maxDays = total / 6;

    for (int i = 1; i <= maxDays; ++i) {
        if (c > 0)
            --c;
        else if (b >= 2 && a >= 2)
            --b, --a;
        else if (a >= 4)
            a -= 3;
        else if (b >= 3) {
            b -= 2;
            ++a;
            ++cutCnt;
        }
        else {
            maxDays = i;
            break;
        }

        if (b > 0) {
            --b;
        } else if (a >= 3) {
            a -= 2;
        } else if (c > 0) {
            --c; ++a;
            ++cutCnt;
        } else {
            maxDays = i;
            break;
        }

        if (a > 0) --a;
        else if (b > 0) {
            --b; ++a;
            ++cutCnt;
        } else if (c > 0) {
            --c; ++b;
            ++cutCnt;
        } else {
            maxDays = i;
            break;
        }

    }

    cout << maxDays << ' ' << cutCnt;
    return 0;
}