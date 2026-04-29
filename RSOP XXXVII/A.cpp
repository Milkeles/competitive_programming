// RSOP XXXVII > A
// Author: H. Hristov
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> pos = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {2, 1}},
    {5, {2, 2}},
    {6, {2, 3}},
    {7, {3, 1}},
    {8, {3, 2}},
    {9, {3, 3}},
    {100, {4, 1}},
    {0, {4, 2}},
    {200, {4, 3}}
};

int dist(int & x1, int & x2, int & y1, int & y2) {
    return (abs(x1 - x2) + abs(y1 - y2));
}

int getDist(int hh, int mm, int ss) {
    int d = dist(pos[hh /10].first, pos[hh%10].first, pos[hh/10].second, pos[hh % 10].second);
    d += dist(pos[hh%10].first, pos[100].first, pos[hh%10].second, pos[100].second);

    d += dist(pos[100].first, pos[mm/10].first, pos[100].second, pos[mm / 10].second);
    d += dist(pos[mm /10].first, pos[mm%10].first, pos[mm/10].second, pos[mm % 10].second);
    d += dist(pos[mm%10].first, pos[100].first, pos[mm%10].second, pos[100].second);

    d += dist(pos[100].first, pos[ss/10].first, pos[100].second, pos[ss / 10].second);
    d += dist(pos[ss /10].first, pos[ss%10].first, pos[ss/10].second, pos[ss % 10].second);
    d += dist(pos[ss%10].first, pos[200].first, pos[ss%10].second, pos[200].second);
    return d;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string time;
        cin >> time;
        int hh = ((time[0] - '0')* 10 + (time[1] - '0')) % 24;
        int mm = ((time[3] - '0') * 10 + (time[4] - '0')) % 60;
        int ss = ((time[6] - '0') * 10 + (time[7]- '0')) % 60;

        int minDist = INT_MAX, minhh, minmm, minss;
        while(hh <= 99) {
            int m = mm;
            while(m <= 99) {
                int s = ss;
                while(s <= 99) {
                    int curDist = getDist(hh, m, s);
                    if (curDist < minDist) {
                        minDist = curDist;
                        minhh = hh;
                        minmm = m;
                        minss = s;
                    }
                    s += 60;
                }
                m += 60;
            }
            hh += 24;
        }
        cout << ((minhh > 9) ? (to_string(minhh)) : "0" + (to_string(minhh)) ) << ':' 
             <<((minmm > 9) ? (to_string(minmm)) : "0" + (to_string(minmm))) << ':'
             << ((minss > 9) ? (to_string(minss)) : "0" + (to_string(minss))) << '\n';
    }
}

/*
5
03:00:00
07:00:00
12:34:44
14:19:00
00:11:59
*/