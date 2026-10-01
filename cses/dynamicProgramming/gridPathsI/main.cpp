#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

vector<vector<ll>> d = {{-1,0},{0,-1}};

int main() {
    fast_io;
    ll n;
    cin >> n;

    vector<string> g(n);
    for (auto &x:g)	cin >> x;

    vector<vector<ll>> dp(n,vector<ll>(n,0));
    dp[0][0]=1;

    for (ll i=0;i<n;i++) {
	    for (ll j=0;j<n;j++) {
		    if (g[i][j]=='*') {
			    dp[i][j]=0;
			    continue;
		    }
		    for (auto x:d) {
			    ll a = i+x[0];
			    ll b = j+x[1];
			    if (a>=0 && b>=0)	dp[i][j]=(dp[i][j]+dp[a][b])%(ll)(1e9+7);
		    }
	    }
    }

    cout << dp[n-1][n-1] << "\n";

    return 0;
}
