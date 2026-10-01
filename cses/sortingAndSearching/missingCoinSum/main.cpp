#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x:v)	cin >> x;
    
    sort(v.begin(),v.end());

    ll res=0;
    for (auto x:v) {
	    if (x<=res+1) {
		    res+=x;
	    }
	    else	break;
    }

    cout << res+1 << "\n";
    return 0;
}
