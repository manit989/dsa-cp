#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    int n;
    cin >> n;

    int p = 1;
    for (int i=0;i<n;i++) {
	    int x;
	    cin >> x;
	    p*=x;
    }

    cout << (p%67 ? "NO" : "YES") << "\n";
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
