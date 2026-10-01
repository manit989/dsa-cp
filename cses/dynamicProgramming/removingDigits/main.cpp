#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;

    for (int i=1;i<=n;i++) {
		int k = i;
		while (k!=0) {
			if (k%10!=0 && i-(k%10)>=0)	dp[i] = min(dp[i],1+dp[i-(k%10)]);
			k/=10;
		}
    }

    cout << dp[n] << "\n"; 
    return 0;
}
