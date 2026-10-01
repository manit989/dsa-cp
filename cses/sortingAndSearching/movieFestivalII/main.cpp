#include <bits/stdc++.h>
#include <set>
#include <utility>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n,k;
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);
    for (auto &x:v)	cin >> x.first >> x.second;

    sort(v.begin(),v.end(),[](auto &l,auto &r){
	if (l.second==r.second) {
	return l.first<r.first;
	}
	return l.second<r.second;
    });

    ll res=0;

    multiset<ll> w; 
    for (ll i=0;i<k;i++)	w.insert(0LL);

    for (auto x:v) {
	    auto it = w.upper_bound(x.first);
	    if (it==w.begin())	continue;
	    it--;
	    if (*it<=x.first) {
		    w.erase(it);
		    w.insert(x.second);
		    res++;
	    }
    }

    cout << res << "\n";

    return 0;
}
