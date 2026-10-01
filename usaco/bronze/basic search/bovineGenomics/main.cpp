#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("cownomics.in", "r", stdin);
     freopen("cownomics.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n,m;
     ll res = 0;
     cin >> n >> m;

     vector<string> v(2*n);

     for (int i=0;i<2*n;i++)	cin >> v[i];
     
     for (int i=0;i<m;i++) {
	     set<char> s;
	     bool b = true;
	     for (int j=0;j<n;j++)	s.insert(v[j][i]);

	     for (int j=n;j<2*n;j++) {
		     if (s.count(v[j][i])) {
			     b=false;
			     break;
		     }
	     }

	     if (b)	res++;
     }

     cout << res;

}
