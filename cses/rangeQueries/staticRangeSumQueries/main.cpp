#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n,q;
    cin >> n >> q;

    vector<ll> v;
    v.push_back(0LL);
    for (int i=0;i<n;i++) {
	    int x;
	    cin >> x;
	    v.push_back(v.back()+x);
    }

    for (int i=0;i<q;i++) {
	    int a,b;
	    cin >> a >> b;
	    cout << v[b]-v[a-1] << "\n";
    }
    return 0;
}
