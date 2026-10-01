#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n,k,x,a,b,c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    vector<ll> v;
    v.push_back(x);
    for (int i=1;i<n;i++) {
	    v.push_back((a*v.back()+b)%c);
    }
    ll ws = 0;
    ll sum = 0;
    ll res = 0;

    for (int i=0;i<n;i++) {
	    sum+=v[i];
	    ws++;
	    if (ws==k) {
		res^=sum;
		sum-=v[i+1-k];
		ws--;
	    }
    }

    cout << res << endl;
    return 0;
}
