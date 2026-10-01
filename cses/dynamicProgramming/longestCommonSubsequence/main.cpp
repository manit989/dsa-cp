#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;

	vector<int> a1(n);
	vector<int> a2(m);

	for (auto &x:a1)	cin >> x;
	for (auto &x:a2)	cin >> x;

	vector<vector<int>> dp(n+1,vector<int>(m+1,rand()));

	
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (a1[i-1]==a2[j-1]) {
				dp[i][j]=1+dp[i-1][j-1];
			}
			else	dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}

	vector<int> seq;

	int i=n;
	int j=m;

	while (i!=0 && j!=0) {
		if (a1[i-1]==a2[j-1]) {
			seq.push_back(a1[i-1]);
			i--;
			j--;
		}
		else {
			if (dp[i-1][j]>dp[i][j-1])	i--;
			else	j--;
		}
	}
	reverse(seq.begin(),seq.end());

	cout << dp[n][m] << "\n";
	for (auto x:seq)	cout << x << " ";
	cout << endl;
}
