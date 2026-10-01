#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("pairup.in", "r", stdin);
     freopen("pairup.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;
     
     vector<pair<int,int>> v(n);
     for (int i=0;i<n;i++) {
	     int f,x;
	     cin >> f >> x;
	     v[i]={x,f};
     }

     sort(v.begin(),v.end());

     int res = INT_MIN;

     int l=0,r=n-1;

     while (l<r) {
	     res=max(res,v[l].first+v[r].first);
	     v[l].second--;
	     v[r].second--;
	     if (v[l].second==0)	l++;
	     if (v[r].second==0)	r--;
     }

     cout << res << "\n";
}
