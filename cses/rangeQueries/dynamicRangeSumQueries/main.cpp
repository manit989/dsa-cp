#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

ll n;
vector<ll> bit;

ll sum(ll k) {
	ll s=0;
	while (k>=1) {
		s+=bit[k];
		k-=k&-k;
	}
	return s;
}

void update(ll k,ll v) {
	while (k<=n) {
		bit[k]+=v;
		k+=k&-k;
	}
}

int main() {
    fast_io;
    ll q;
    cin >> n >> q;

    vector<ll> v(n);
    for (auto &x:v)	cin >> x;
    bit.resize(n+1,0);

    for (ll i=0;i<n;i++)	update(i+1,v[i]);

    for (ll i=0;i<q;i++) {
	    ll qt,a,b;
	    cin >> qt >> a >> b;

	    if (qt==1) {
		    update(a,b-v[a-1]);
		    v[a-1]=b;
	    }
	    else	cout << sum(b)-sum(a-1) << "\n";
    }

    return 0;
}
