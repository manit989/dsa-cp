#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("whereami.in", "r", stdin);
     freopen("whereami.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;
     string h;
     cin >> h;

     for (int i=1;i<=n;i++) {
	     set<deque<char>> s;
	     deque<char> d;
	     bool b = true;
	     for (auto x:h) {
		     if (d.size()==i) {
			     d.pop_front();
			     d.push_back(x);
		     }
		     else	d.push_back(x);
		     if (s.count(d)) {
			     b=false;
			     break;
		     }
		     else	s.insert(d);
	     }
	     if (b) {
		     cout << i << "\n";
		     return 0;
	     }
     }

     return -1;
}
