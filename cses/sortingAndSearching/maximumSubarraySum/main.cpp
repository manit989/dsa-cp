#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<ll> v(n);

    for (auto &x:v)	cin >> x;
    
    ll res=v[0];
    ll sum=v[0];

    for (int i=1;i<n;i++) {
	    sum=max(sum+v[i],v[i]);
	    res=max(sum,res);
    }

    cout << res << endl;

    return 0;
}
