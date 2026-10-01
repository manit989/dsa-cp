#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
        ll n;
        cin >> n;

        vector<ll> dp(n+1,0);
        ll mod = 1e9+7;
        dp[0]=1;

        for (ll i=1;i<=n;i++) {
                for (ll j=1;j<=6;j++) {
                        if (i-j>=0) {
                                dp[i]+=dp[i-j];
                                dp[i]%=mod;
                        }
                }
        }

        cout << dp[n]%mod << endl;
}
