#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("lostcow.in", "r", stdin);
     freopen("lostcow.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll x=0,y=0,res=0;
     cin >> x >> y;
     ll current=x;

     for (int i=0; ;i++) {
	     ll next = x + (i%2==0 ? (1LL<<i) : -(1LL<<i));
	     res+=abs(next-current);
	     if ((y>=current && y<=next) || (current>=y && y>=next)) {
		     res-=abs(next-y);
		     cout << res << endl;
		     break;
	     }
	     current=next;
     }
}
