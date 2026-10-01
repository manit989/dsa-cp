#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long


int main() {
    fast_io;
    int n,m;
    cin >> n >> m;

    vector<int> coins(n);
    for (auto &x:coins)	cin >> x;

    vector<int> dp(m+1,0);
    dp[0]=1;

    for (auto x:coins) {
	    for (int i=1;i<=m;i++) {
		    if (i-x>=0) {
			    dp[i]+=dp[i-x];
			    dp[i]=dp[i]%(int)(1e9+7);
		    }
	    }
    }

    cout << dp[m] << "\n";

    return 0;
}

