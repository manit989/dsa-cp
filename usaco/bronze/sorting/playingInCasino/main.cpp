#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	int m;
	cin >> n >> m;

	vector<vector<int>> v;

	for (int i=0;i<n;i++) {
		vector<int> t;
		for (int j=0;j<m;j++) {
			ll x;
			cin >> x;
			t.push_back(x);
		}
		v.push_back(t);
	}

	int res = 0;

	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			for (int k=0;k<m;k++)	res+=abs(v[i][k]-v[j][k]);
		}
	}

	cout << res << "\n";
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     for (int i=0;i<n;i++)	solve();
}
