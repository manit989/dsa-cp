#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;
    
    vector<pair<ll,ll>> q(n);
    for (auto &x:q)	cin >> x.first >> x.second;

    ll m;
    cin >> m;

    vector<string> w(m);
    for (auto &x:w)	cin >> x;

    vector<set<char>> we(n);
    for (ll i=0;i<n;i++) {
	    ll a = q[i].first;
	    ll b = q[i].second-1;

	    for (auto y:w) {
		    if (a==(ll)y.size() && b<(ll)y.size()) {
			    we[i].insert(y[b]);
		    }
	    }
    }

    for (auto y:w) {
	    if (y.size()!=n) {
		    cout << "No" << "\n";
		    continue;
	    }
	    bool possible=true;
	    for (ll i=0;i<n;i++) {
		    if (i<(ll)y.size() && we[i].count(y[i]))	continue;
		    else {
			    possible=false;
			    break;
		    }
	    }
	    if (possible) {
		    cout << "Yes" << "\n";
	    }
	    else {
		    cout << "No" << "\n";
	    }
    }

    return 0;
}
