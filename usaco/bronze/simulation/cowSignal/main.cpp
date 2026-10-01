#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("cowsignal.in", "r", stdin);
     freopen("cowsignal.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     
     ll m,n,k;

     cin >> m >> n >> k;

     vector<string> v(m);

     for (string &x:v)	cin >> x;


     vector<string> ans(2*m);

     for (auto x:v) {
	     string s = "";
	     for (auto y:x) {
		     for (int i=0;i<k;i++)	s.push_back(y);
	     }
	     for (int i=0;i<k;i++)	cout << s << "\n";
     }
}
