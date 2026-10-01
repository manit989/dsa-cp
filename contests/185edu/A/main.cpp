#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;

	if (n==1) {
		cout << 1 << "\n";
		return;
	}
	else if (n==2) {
		cout << 9 << "\n";
		return;
	}

	cout << max({4*pow(n,2)-n-4,5*pow(n,2)-5*n-5,4*pow(n,2)-4*n-4}) << "\n";
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     while (n--)	solve();
}
