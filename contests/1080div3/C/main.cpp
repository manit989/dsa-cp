#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
	int n;
	cin >> n;

	if (n==1) {
		cout << 0 << "\n";
		return;
	}

	int res=0;

	vector<int> v(n);
	for (auto &x:v)	cin >> x;

	for (int i=0;i<n;i++) {
		int b = v[(i+1)%n];
		int f = v[(n+i-1)%n];

		if (b==7-((i+1)%n) || f==7-((n+i-1)%n)) {
			for (int j=1;j<6;j++) {
				if (j!=7-v[i] && j!=7-b && j!=7-f) {
					v[i]=j;
					break;
				}
			}
			res++;
		}
	}

	cout << res << "\n";

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
