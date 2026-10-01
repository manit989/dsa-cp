#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> unshuffle(vector<int> a,vector<int> id) {
	int n = a.size();
	vector<int> v(n);

	for (int i=0;i<n;i++) {
		v[i]=id[a[i]-1];
	}

	return v;
}

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> id(n);

	for (int i=0;i<n;i++)	cin >> a[i];
	for (int i=0;i<n;i++)	cin >> id[i];

	id  = unshuffle(a,id);
	id  = unshuffle(a,id);
	id  = unshuffle(a,id);

	for (auto x:id)	cout << x << "\n";

}
