#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve(int n,int s,int d) {
	if (n==1) {
		cout << s << " " << d << "\n";
		return;
	}
	solve(n-1,s,6-s-d);
	cout << s << " " << d << "\n";
	solve(n-1,6-s-d,d);
}

int main() {
    fast_io;
    int n;
    cin >> n;

    cout << pow(2,n)-1 << "\n";
    solve(n,1,3);

    return 0;
}
