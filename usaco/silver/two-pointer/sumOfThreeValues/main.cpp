#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n,t;
     cin >> n >> t;

     if (n<3) {
	     cout << "IMPOSSIBLE" << "\n";
	     return 0;
     }

     vector<pair<int,int>> v(n);
     for (int i=0;i<n;i++) {
	     int a;
	     cin >> a;
	     v[i]={a,i};
     }

     sort(v.begin(),v.end());

     for (int i=0;i<n;i++) {
	     int l=0,r=n-1;
	     while (l<r) {
		     if (v[l].second==v[i].second) {
			     l++;
			     continue;
		     }
		     else if (v[r].second==v[i].second) {
			     r--;
			     continue;
		     }
		     if (v[i].first+v[l].first+v[r].first==t) {
			     cout << v[l].second+1  << " " << v[i].second+1 << " " << v[r].second+1;
			     return 0;
		     }
		     if (v[i].first+v[l].first+v[r].first<t)	l++;
		     else	r--;
	     }
     }

     cout << "IMPOSSIBLE" << "\n";
}
