#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

ll mod = 1e9+7;

ll sexp(ll i) {
	if (i==1)	return 2;
	else if (i%2)	return (2*sexp(i-1))%mod;
	return (sexp(i/2)*sexp(i/2))%mod;
}

int main() {
    fast_io;
    ll n;
    cin >> n;

    cout << sexp(n) << "\n";
    return 0;
}
