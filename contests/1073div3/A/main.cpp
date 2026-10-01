#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
	int n,s,x;
	cin >> n >> s >> x;

	vector<int> v(n);
	for (auto &x:v) {
		cin >> x;
	}

	int cs = accumulate(v.begin(),v.end(),0);

	if (cs>s || (s-cs)%x!=0) {
		cout << "NO" << endl;
	}

	else	cout << "YES" << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
