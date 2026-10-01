#include <bits/stdc++.h>
#include <cmath>
#include <utility>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll unsigned long long
ll mod = 1e9+7;

int main() {
    fast_io;
    ll n;
    cin >> n;

    ll a = 0;
    ll b = 1;

    if (n==0) {
	    cout << 0 << "\n";
    }
    else if (n==1) {
	    cout << 1 << "\n";
    }
    else {
	    ll c = a+b;
	    for (int i=0;i<n-2;i++) {
		    ll t = b;
		    a=t%mod;
		    b=c%mod;
		    c=(c+t)%mod;
	    }
	    cout << c << "\n";
    }

    return 0;
}
