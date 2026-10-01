#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;
     vector<int> v(n);

     for (int i=0;i<n;i++)	cin >> v[i];

     int avg = 0;
     for (auto x:v)	avg+=x;
     avg/=n;

     int res=0;

     for (int i=0;i<n;i++) {
	     for (int j=i;j<n;j++) {
		     if (v[j]==avg) {
			     res+=n-i;
			     break;
		     }
	     }
     }

     cout << res;
}
