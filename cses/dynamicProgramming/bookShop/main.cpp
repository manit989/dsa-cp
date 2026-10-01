#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n,t;
    cin >> n >> t;


    vector<int> h(n);
    vector<int> s(n);
    for (auto &x:h)	cin >> x;
    for (auto &x:s)	cin >> x;

    vector<int> dp(t+1,0);
    
    for (int i=n-1;i>=0;i--) {
	for (int j=t;j>=1;j--) {
		if (j-h[i]>=0) {
			dp[j]=max(dp[j],s[i]+dp[j-h[i]]);
		}
	}
    }

    cout << dp[t] << "\n";
    return 0;
}
