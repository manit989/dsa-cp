#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
   setIO("traffic");
    ll n;
    cin >> n;

    vector<string> r(n);
    vector<ll> l(n);
    vector<ll> u(n);

    for (int i=0;i<n;i++)	cin >> r[i] >> l[i] >> u[i];

    ll a=0;
    ll b=1e9;

    for (int i=n-1;i>=0;i--) {
	    if (r[i]=="none") {
		    a=max(a,l[i]);
		    b=min(b,u[i]);
	    }
	    else if (r[i]=="on") {
		    a-=u[i];
		    b-=l[i];
		    a=max(0LL,a);
	    }
	    else {
		    a+=l[i];
		    b+=u[i];
	    }
    }

    cout << a << " " << b << "\n";

    a=0;
    b=1e9;

    for (int i=0;i<n;i++) {
	    if (r[i]=="none") {
		    a=max(a,l[i]);
		    b=min(b,u[i]);
	    }
	    else if (r[i]=="off") {
		    a-=u[i];
		    b-=l[i];
		    a=max(0LL,a);
	    }
	    else {
		    a+=l[i];
		    b+=u[i];
	    }
    }

    cout << a << " " << b << "\n";
    
    return 0;
}
