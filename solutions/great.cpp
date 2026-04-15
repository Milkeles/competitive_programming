// Национална олимпиада - Национален кръг > D > 2026 > great
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int cmp(string & a, string & b) {
    int i = 0;
    while(i < b.size() && b[i] == '0') ++i;

    if ((b.size() - i) != a.size()) {
        if (a.size() > (b.size() - i)) return -1;
        else return 1;
    }

    for (int j = 0; j < a.size(); ++i, ++j) {
        if (a[j] == b[i]) continue;

        if (a[j] > b[i]) return -1;
        else return 1;
    }

    return 0;
}

int bs(string & num) {
    int res = -1;
    int l = 0, r = num.size(), temp;
    while(l <= r) {
        int mid = (l + r) >> 1;
        string a = num.substr(0, mid);
        string b = num.substr(mid);
        // cout << a << ' ' << b << '\n';
        temp = cmp(a, b);

        if (temp == 0) return mid;
        else if (temp == 1) l = mid + 1;
        else r = mid - 1;
    }

    return res;
}

// Author: Greedy
int solve(string &num) {
    int mid = num.size() >> 1;

    string a = num.substr(0, mid);
    string b = num.substr(mid);

    int i = 0;
    while (i < b.size() && b[i] == '0') i++;
    b = b.substr(i);

    int len = b.size();

    if (a.substr(0, len) != b) return -1;

    for (int j = len; j < a.size(); j++) {
        if (a[j] != '0') return -1;
    }

    return len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        string num;
        cin >> num;
        cout << bs(num) << '\n';
    }
}