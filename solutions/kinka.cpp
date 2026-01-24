// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    cin >> num;
    num = '0' + num;
    vector<int> gcd(num.length() + 1);
    gcd[0] = 0;
    for (int i = 0; i < num.length(); i++)
        gcd[i + 1] = __gcd(gcd[i], num[i] - '0');

    string res = "";

    for (int i = num.length() - 1; i >= 0; i--)
    {
        if (gcd[i] == 1)
            continue;
        for (char j = num[i] + 1; j <= '9'; j++)
        {
            if (__gcd(gcd[i], j - '0') > 1)
            {
                res = num.substr(0, i) + j + string(num.length() - i - 1, '0');
                break;
            }
        }

        if (res != "")
            break;
    }

    if (res[0] == '0')
        res = res.substr(1);
    cout << res;
    return 0;
}