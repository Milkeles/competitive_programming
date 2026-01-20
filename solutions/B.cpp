#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

using p = pair<long long, long long>;
using ll = long long;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, count = 0;
    cin >> N;

    vector<p> a;
    ll m = ceil(N/2.0);
    for(ll i = 0; i <= m; i++){
        ll diff = i * i - N;
        if(diff < 0){
            continue;
        }

        ll num = sqrt(diff);
        if(num * num == diff){
            count++;
            p m = make_pair(i * i, diff);
            a.push_back(m);
        }

    }

    cout << count << endl;
    for(auto m : a){
        cout << m.first << " " << m.second << endl;
    }
    return 0;
}