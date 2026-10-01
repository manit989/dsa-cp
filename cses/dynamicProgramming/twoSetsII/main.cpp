#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<int> dp(n+1,0);

    int m = 1e9 + 7;

    if ((n%2 ? (n+1)/2 : n/2)%2) {
	    cout << 0 << "\n";
	    return 0;
    }	
    
    for (int i=3;i<=n;i++) {
	    dp[i]=dp[i-1];
	    if ((i%2 ? (i+1)/2 : i/2)%2)	continue;
	    vector<int> v(i+1,0);
	    v[0]=1;
	    for (int j=0;j<i;j++) {
		    for (int k=0;k<=i;k++)	if (k-j>=0)	v[k]+=v[k-j];
	    }
	    dp[i]+=+v[i]%m;
    }

    cout << dp[n] << "\n";
    return 0;
}
