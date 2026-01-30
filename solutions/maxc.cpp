// Национална олимпиада / Национален кръг / D / 2021 / maxc
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bool comp(const string& a, const string& b) {
    return (a + b) > (b + a); //220 or 202
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> nums(n);
    for(string & x : nums) cin >> x;

    sort(nums.begin(), nums.end(), comp);

    for(string & x : nums) cout << x;
} // Is this for real?