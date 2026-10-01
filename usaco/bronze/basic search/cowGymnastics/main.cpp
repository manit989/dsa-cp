#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("gymnastics.in", "r", stdin);
     freopen("gymnastics.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n,k;
     cin >> k >> n;

     vector<map<int,int>> v(k);

     ll res = 0;

     for (int i=0;i<k;i++) {
	     for (int j=0;j<n;j++) {
		     int a;
		     cin >> a;
		     v[i][a]=j;
	     }
     }

     for (int i=1;i<=n;i++) {
	     for (int j=1;j<=n;j++) {
		     if (i==j)	continue;
		     bool val = true;
		     for (auto x:v){
			     if (x[i]<x[j]) {
				     val=false;
				     break;
			     }
		     }
		     if (val)	res++;
	     }
     }

     cout << res;
}
