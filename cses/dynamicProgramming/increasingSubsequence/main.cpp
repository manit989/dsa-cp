#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x: v)	cin >> x;

    const int INF = 1e9;
    vector<int> dp(n+1,INF);
    dp[0]=-INF;

    for (int i=0;i<n;i++) {
	    int l = upper_bound(dp.begin(),dp.end(),v[i])-dp.begin();
	    if (dp[l-1]<v[i] && v[i]<dp[l]) {
		    dp[l]=v[i];
	    }
    }

    int ans = 0;
    for (int l=0;l<=n;l++) {
	    if (dp[l]<INF) {
		    ans=l;
	    }
    }

    cout << ans << "\n";

    return 0;
}
