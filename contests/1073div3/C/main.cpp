#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    int n,q;
    cin >> n >> q;


    vector<int> a(n),b(n);

    for (auto &x:a)	cin >> x;
    for (auto &x:b)	cin >> x;

    vector<int> dp(n);
    dp[n-1]=max(a[n-1],b[n-1]);

    for (int i=n-2;i>=0;i--) {
	    dp[i]=max({a[i],dp[i+1],b[i]});
    }

    vector<int> p(n);
    p[0]=dp[0];

    for (int i=1;i<n;i++)	p[i]=dp[i]+p[i-1];

    for (int i=0;i<q;i++) {
	    int a;
	    int b;
	    cin >> a >> b;
	    a--;
	    b--;

	    if (a==0)	cout << p[b] << " ";
	    else	cout << p[b]-p[a-1] << " ";
    }
    cout << endl;

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
