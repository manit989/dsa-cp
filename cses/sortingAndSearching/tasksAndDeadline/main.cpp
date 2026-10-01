#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(2));

    for (auto &x:a)
	    cin >> x[0] >> x[1];

    sort(a.begin(),a.end());

    ll endTime=0;
    ll res=0;
    for (auto x:a) {
	    endTime+=x[0];
	    res+=x[1]-endTime;
    }

    cout << res << "\n";
    
    return 0;
}
