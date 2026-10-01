#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("diamond.in", "r", stdin);
     freopen("diamond.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     int n,k;
     cin >> n >> k;
     vector<int> v(n);
     int res = INT_MIN;

     for (int i=0;i<n;i++)	cin >> v[i];

     for (int i=0;i<n;i++) {
	     int m = 0;
	     for (int j=0;j<n;j++) {
		     if (v[i]<=v[j]&& v[j]<=v[i]+k) {
			     m++;
		     }
	     }
	     res=max(res,m);
     }
     

     cout << res;
}
