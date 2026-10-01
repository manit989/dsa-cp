#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &x:v)	cin >> x;

    vector<ll> prefix(n+1,0);
    prefix[1]=v[0];
    vector<ll> suffix(n+1,0);
    suffix[n-1]=v[n-1];

    for (int i=1;i<n;i++) {
	    prefix[i+1]+=prefix[i]+v[i];
    }
    for (int i=n-2;i>=0;i--) {
	    suffix[i]+=v[i]+suffix[i+1];
    }
    vector<ll> dp(n);

    for (auto x:dp)	cout << x << " ";
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
