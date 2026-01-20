#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll a, b;
    cin >> a >> b;
    ll maxC = a + b - 1, minC;
    minC = max(a, b) - min(a, b);

    cout << maxC - minC;

}