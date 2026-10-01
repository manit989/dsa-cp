#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (auto &x:v)	cin >> x;

    vector<ll> ns(n);
    vector<ll> ps(n);

    stack<ll> s;
    for (ll i=0;i<n;i++) {
	while (!s.empty() && v[s.top()]>=v[i])	s.pop();
	ps[i] = s.empty() ? -1 : s.top();
	s.push(i);
    }

    for (ll i=0;i<n;i++) {
	    if (ps[i]==-1)	cout << 0 << " ";
	    else	cout << ps[i]+1 << " ";
    }
    cout << "\n";

    return 0;
}
