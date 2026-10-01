#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
	    ll a,b;
	    cin >> a >> b;

	    ll x = a+b;
	    if (x%3==0 && 2*min(a,b)>=max(a,b)) {
		    cout << "YES" << "\n";
	    }
	    else {
		    cout << "NO" << "\n";
	    }
    }
    return 0;
}
