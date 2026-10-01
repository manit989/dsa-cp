#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("blocks.in", "r", stdin);
     freopen("blocks.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     int n;
     cin >> n;

     vector<pair<string,string>> v;
     for (int i=0;i<n;i++) {
	     string s1,s2;
	     cin >> s1 >> s2;
	     v.push_back({s1,s2});
     }

     vector<int> arr(26);

     for (char c='a';c<='z';c++) {
	     int res = 0;
	     for (auto x:v) {
		     int s1c = 0;
		     int s2c = 0;
		     for (auto c1:x.first)	if (c1==c)	s1c++;
		     for (auto c2:x.second)	if (c2==c)	s2c++;
		     res += max(s1c,s2c);
	     }
	     arr[c-97]+=res;
     }

     for (auto x:arr)	cout << x << "\n";

}
