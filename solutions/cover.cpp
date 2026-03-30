#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXC = 10000001;

int diff[MAXC + 1];

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
       int x, y;
       cin >> x >> y;
       diff[x]++;
       diff[y]--;
   }
   ll maxCnt = 0, cur = 0, len = 0;
   for (int i = 0; i < MAXC; i++) {
       cur += diff[i];
       if (cur > maxCnt) {
           maxCnt = cur;
           len = 1;
       } else if (cur == maxCnt && maxCnt > 0) {
           len++;
       }
   }

   cout << maxCnt << '\n' << len;
   return 0;
}