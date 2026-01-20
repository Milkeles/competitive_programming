#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    short n;
    cin >> n;
    int max = 0;
    while (n--) {
        short hh, mm, l;
        cin >> hh >> mm >> l;
        int cur = hh * 60 + mm + l;
        if (cur > max) {
            max = cur;
        }
    }

    max = max % 1440;
    cout << max / 60 << ' ' << max % 60;
}