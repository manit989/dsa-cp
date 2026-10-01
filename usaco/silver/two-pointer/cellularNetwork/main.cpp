#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n,m;
     cin >> n >> m;

     vector<ll> c(n);
     vector<ll> t(m);

     for (int i=0;i<n;i++) {
	     cin >> c[i];
     }

     for (int i=0;i<m;i++) {
	     cin >> t[i];
     }

     ll res = 0;

     int j=0;

     for (int i=0;i<n;i++) {
	     while (j<m+1 && abs(c[i]-t[j+1])<=abs(c[i]-t[j]))	j++;
	     res = max(res,abs(c[i]-t[j]));
     }

     cout << res << "\n";
}
