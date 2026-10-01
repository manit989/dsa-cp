#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;

	vector<ll> v;
	for (int i=0;i<n;i++) {
		ll a;
		cin >> a;
		if (a>0)	v.push_back(a);
	}
	sort(v.begin(),v.end());
	ll sum=accumulate(v.begin(),v.end(),0LL);

	if (n==v.size() && sum==n) {
		cout << 1 << "\n";
		return;
	}

	else if (sum>n) {
		cout << v.size() << "\n";
		return;
	}

	int i=0;
	while (sum>v.size()-i && i<v.size()) {
		sum-=v[i];
		i++;
	}

	cout << v.size()-i << "\n";
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     while (n--)	solve();
}
