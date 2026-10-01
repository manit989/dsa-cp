#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x:v)	cin >> x;

    for (int i=0;i<n;i++) {
	int cp = i+1;
	int tp = v[i];
	int k = max(tp,cp)/min(tp,cp);

	if (v[i]==cp)	continue;
	else if (max(cp,tp)%2 || k%2) {
		cout << "NO" << "\n";
		return;
	}
	else if ((k&(k-1))!=0) {
		cout << "NO" << "\n";
		return;
	}
    }
    cout << "YES" << "\n";
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
