#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     ll res = n;

     for (int i=1;i<n;i++) {
	     ll x;
	     cin >> x;
	     res+=i;
	     res-=x;
	     
     }

     cout << res << endl;
}
