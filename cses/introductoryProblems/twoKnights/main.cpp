#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long


int main() {
    fast_io;
    ll n;
    cin >> n;

    for (ll i=1;i<=n;i++) {
	    cout << (i*i*i*i-9*i*i+24*i-16)/2 << "\n";
    }

    return 0;
}
