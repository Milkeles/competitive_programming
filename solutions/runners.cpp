#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> runners(n);
    map<int, vector<int>, greater<>> placing;

    for (int i = 0; i < n; ++i) {
        cin >> runners[i];
        placing[runners[i] - i].push_back(runners[i]);
    }

    if (placing.size() < 3) {
        cout << 0 << '\n';
        return 0;
    }

    auto third = placing.begin();
    advance(third, 2);

    cout << third->second.size() << ' ';
    for (int runner : third -> second) cout << runner << ' ';

    return 0;
}
