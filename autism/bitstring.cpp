// Национална олимпиада - Национален кръг > D > 2024
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, cmd;
    cin >> s;
    int t, ones = 0, zeros = 0, id;
    cin >> t;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] != s[i-1]) {
            if(s[i-1] == '0') ++zeros;
            else ++ones;
        }
    }
    if (s.back() == '0') ++zeros;
    else ++ones;

    while(t--) {
        cin >> cmd >> id;
        if (cmd == "Inv") {
            --id;
            s[id] = (s[id] == '1' ? '0' : '1');
            if (id != 0 && id != s.size() - 1) {
                if(s[id-1] == s[id+1] && s[id] != s[id-1]) ++ones, ++zeros;
                if (s[id-1] == s[id+1] && s[id] == s[id-1]) --ones, --zeros;
            }
            else if (id == 0) {
                if (s[id+1] == s[id]) {
                    if(s[id] == '0') --ones;
                    else --zeros;
                }
                else ++ones, ++zeros;
            }
            else if (id == s.size()-1) {
                if (s[id-1] == s[id]) {
                    if(s[id] == '0') --ones;
                    else --zeros;
                }
                else ++ones, ++zeros;
            }
        } else if (cmd == "Print") {
            cout << (id == 1 ? ones : zeros) << '\n';
        }
    }

    return 0;
}

// По някаква причина просто не работи, а идеята е същата като тази на автора.
// Не откривам грешки в индексацията.