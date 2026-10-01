#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("blist.in", "r", stdin);
     freopen("blist.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     vector<int> v(1001,0);
     int n;
     cin >> n;

     for (int i=0;i<n;i++) {
	     int s,t,b;
	     cin >> s >> t >> b;
	     for (int j=s;j<=t;j++)	v[j]+=b;
     }

     cout << *max_element(v.begin(),v.end());
}
