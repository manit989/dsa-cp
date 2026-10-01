#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;

    ll n,s;
    cin >> n >> s;
    
    vector<ll> c(n);
    for (auto &x:c)	cin >> x;
    vector<ll> dp(s+1,INT_MAX);

    dp[0]=0;
    for (ll i=1;i<=s;i++) {
	    for (auto x:c) {
		    if (i-x>=0)	dp[i]=min(dp[i],1+dp[i-x]);
	    }
    }

    cout << (dp[s]==INT_MAX ? -1 : dp[s]) << endl;

    return 0;
}
