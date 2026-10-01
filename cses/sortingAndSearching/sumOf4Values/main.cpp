#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n,t;
    cin >> n>> t;

    vector<ll> v(n);
    for (auto &x:v)	cin >> x;

    vector<vector<ll>> sv;
    for (int i=0;i<n;i++) {
	    for (int j=i+1;j<n;j++) {
		    vector<ll> t = {v[i]+v[j],i,j};
		    sv.push_back(t);
	    }
    }

    map<ll,pair<int,int>> m;
    for (auto x:sv) {
	    if (m.count(t-x[0])) {
		    cout << x[0] << " " << x[1] << " " << m[t-x[0]].first << " " << m[t-x[0]].second << "\n";
		    return 0;
	    }
	    m[x[0]]={x[1],x[2]};
    }

    return 0;
}
