#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;

    vector<pair<ll,ll>> v(n);
    map<pair<ll,ll>,ll> m;
    for (ll i=0;i<n;i++) {
	    cin >> v[i].first >> v[i].second;
	    m[v[i]]=i;
    }

    sort(v.begin(),v.end(),[](auto &l,auto &r){
	return (l.first==r.first) ? l.second>r.second : l.first<r.first;
    });
    
    vector<ll> contains(n,0);
    vector<ll> isContained(n,0);

    ll max_end = INT_MIN;
    for (ll i=0;i<n;i++) {
	    if (v[i].second<=max_end)	isContained[m[v[i]]]=1;
	    max_end=max(max_end,v[i].second);
    }

    ll min_end = INT_MAX;
    for (ll i=n-1;i>=0;i--) {
	    if (v[i].second>=min_end)	contains[m[v[i]]]=1;
	    min_end=min(min_end,v[i].second);
    }

    for (auto x:contains)	cout << x << " ";
    cout << "\n";
    for (auto x:isContained)	cout << x << " ";
    cout << "\n";

    return 0;
}
