#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;

    vector<ll> v(n,0LL);
    for (auto &x:v)	cin >> x;

    ll l=0;
    ll res=0;
    map<ll,ll> m;

    for (ll r=0;r<n;r++) {
	    if (m.count(v[r]))	l=max(m[v[r]]+1,l);
	    m[v[r]]=r;
	    res+=r-l+1;
    }

    cout << res << "\n";

    return 0;
}
