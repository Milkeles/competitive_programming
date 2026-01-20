// Author: H. Hristov
#pragma GCC optimize("O3,unroll-loops,Ofast,avx2,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<bool> getPrimes(int l)
{
  vector<bool> primes(l + 1, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= l; ++i)
  {
    if (!primes[i])
      continue;
    for (int j = i * i; j <= l; j += i)
      primes[j] = false;
  }

  return primes;
}
int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  int maxn = -1;
  for (int &n : nums)
    cin >> n, maxn = max(maxn, n);

  vector<bool> prime = getPrimes(maxn);
  
  int res = 0;
  for (int &num : nums)
  {
    int count = 0;
    for (int x = 2; x <= num/2; ++x) {
      if (prime[x] and prime[num - x]) ++count;
    }
    res = max(res, count);
  }

  cout << res;
  return 0;
}