// Author: H. Hristov
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

bool isPrime[64];
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   vector<int> primes;
   isPrime[0] = isPrime[1] = true;
   primes.push_back(2);
   for(int i = 3; i <= 64; i+=2) {
      if(isPrime[i] || !(i&1)) continue;
      primes.push_back(i);
      for (int j = i * i; j <= 64; j+=i)
         isPrime[j] = true;
   }
   for(int i = 0; i < primes.size(); ++i) {
      int p = primes[i];
      ull mersenne = (1ULL << p) - 1;
      if(p == 2) {
         cout << mersenne << ": " << 6 << '\n';
         continue;
      }
      ull s = 4;
      for(int k = 0; k < p-2; ++k) {
         s = (s * s - 2) % mersenne;
      }
      if(s == 0)
         cout << mersenne << ": " << mersenne*(1LL << (p - 1)) << '\n';
   }
   
   return 0;
}