#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &x:v)	cin >> x;

    vector<ll> p(n+1,0LL);
    for (int i=1;i<=n;i++)	p[i]=p[i-1]+v[i-1];

    map<ll,int> m;
    m[0]=1;

    ll res=0;
    for (int i=1;i<=n;i++) {
	    ll k = (p[i]+n*(abs(p[i]/n)+1))%n;
	    res += m.count(k) ? m[k] : 0LL;
	    if (m.count(k))	m[k]++;
	    else	m[k]=1LL;
    }

    cout << res << "\n";

    return 0;
}
