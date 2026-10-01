#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll unsigned long long
ll mod = 1e9+7;

ll getExp(ll a,ll b) {
	if (b==1)	return a % mod;
	else {
		if (b%2)	return (a*getExp(a,b-1))%mod;
		else	return getExp((a*a)%mod,b/2);
	}
}

int main() {
    fast_io;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
	    ll a,b;
	    cin >> a >> b;

	    if (b==0)	cout << 1 << "\n";
	    else if (a==0)	cout << 0 << "\n";
	    else {
		cout << getExp(a,b) << "\n";
	    }
    }
    return 0;
}
