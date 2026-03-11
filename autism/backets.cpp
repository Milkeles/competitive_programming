// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    vector<pair<int,int>> pairs;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            int open = st.top();
            st.pop();
            pairs.push_back({open, i});
        }
    }

    int k = pairs.size();
    set<string> results;

    for (int mask = 1; mask < (1 << k); mask++) {
        vector<bool> remove(s.size(), false);

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                remove[pairs[i].first] = true;
                remove[pairs[i].second] = true;
            }
        }

        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (!remove[i])
                t += s[i];
        }

        results.insert(t);
    }

    for (auto &x : results)
        cout << x << "\n";
}

// Coming up with a solutin and not being able to write it because you forgot the syntax and basic string processing of all things is just a new kind of autism.
// Work on that.
