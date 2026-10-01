#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("circlecross.in", "r", stdin);
     freopen("circlecross.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     string s;
     cin >> s;
     int n = 52;

     map<char,vector<int>> m;

     for (int i=0;i<n;i++)	m[s[i]].push_back(i);

     ll res = 0;

     for (char c='A';c<='Z';c++) {
	     for (char d='A';d<='Z';d++) {
		     if (c==d)	continue;
		     int i = m[c][0];
		     int j = m[c][1];
		     int k = m[d][0];
		     int l = m[d][1];
		     i=min(i,j);
		     j=max(i,j);
		     k=min(k,l);
		     l=max(k,l);

		     if ((i<=k && k<=j) && (j<=l && k<=j))	res++;
	     }
     }

     cout << res;
}
