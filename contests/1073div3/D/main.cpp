#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll unsigned long long

ll getScore(vector<ll> &a,vector<ll> &b,ll m) {
	ll n = a.size();

	ll sw=n-m;
	ll lvl=0;

	for (int i=0;i<n;i++) {
		if (sw<b[i])	break;
		else {
			sw-=b[i];
			lvl++;
		}
	}

	return lvl*a[m];
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n),b(n);

    for (auto &x:a)	cin >> x;
    for (auto &x:b)	cin >> x;

    sort(a.begin(),a.end());
    if (a[0]==a[n-1]) {
	    cout << getScore(a,b,0) << endl;
	    return;
    }
    ll l=0;
    ll h=n-1;

    ll res=0;
    while (l<=h) {
	    ll m = l+(h-l)/2;
	    ll score = getScore(a,b,m);
//	    cout << score << endl;

	    if (score==0) {
		    h=m-1;
	    }
	    else {
		    res=max(res,score);
		    l=m+1;
	    }
    }

    cout << res << endl;
}

int main() {
    fast_io;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
