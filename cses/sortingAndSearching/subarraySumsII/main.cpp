#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n,t;
    cin >> n >> t;
    vector<ll> v(n);

    for (auto &x:v)	cin >> x;
    vector<ll> p(n+1,0LL); 

    for (int i=1;i<=n;i++)	p[i]=v[i-1]+p[i-1];

    map<ll,ll> m;
    m[0]=1;

    ll res=0;

    for (int i=1;i<=n;i++) {
	    res+=m.count(p[i]-t) ? m[p[i]-t] : 0;
	    if (m.count(p[i]))	m[p[i]]++;
	    else	m[p[i]]=1;
    }

    cout << res << "\n";
    
    return 0;
}
