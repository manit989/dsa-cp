#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

vector<string> b(8);

vector<bool> row(8);
vector<bool> col(8);
vector<bool> diag1(15);
vector<bool> diag2(15);

int res = 0;

void solve(int r) {
	if (r==8) {
		res++;
		return;
	}
	for (int c=0;c<8;c++) {
		if (b[r][c]=='*' || row[r] || col[c] || diag1[r+c] || diag2[r-c+7])	continue;
		row[r]=col[c]=diag1[r+c]=diag2[r-c+7]=true;
		solve(r+1);
		row[r]=col[c]=diag1[r+c]=diag2[r-c+7]=false;
	}
}

int main() {
    fast_io;
    for (auto &x:b)	cin >> x;

    solve(0);

    cout << res << "\n";

    return 0;
}
