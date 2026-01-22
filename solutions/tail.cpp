// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#define ll long long
using namespace std;
int main() {
    ll a, b;
    cin >> a >> b;
    ll one = ((b % 10 == 0) ? b : (10 * ((b - 1)/10))) - (10 * ((a - 1)/10));
    one /= 10;
    ll two = ((b % 100 == 0) ? b : (100 * ((b - 1)/100))) - (100 * ((a - 1)/100));
    two /= 100;
    ll three = ((b % 1000 == 0) ? b : (1000 * ((b - 1)/1000))) - (1000 * ((a - 1)/1000));
    three /= 1000;
    ll more = ((b % 10000 == 0) ? b : (10000 * ((b - 1)/10000))) - (10000 * ((a - 1)/10000));
    more /= 10000;
    cout << (one - ((two - three) + three)) << '\n' << two - three << '\n' << three - more;
}