#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);


     ll n;
     cin >> n;

     while (n--) {
	     ll y,x;
	     cin >> y >> x;
	     ll t = max(x,y);

	     if (t%2) {
		ll i = t*t-t+1;
		while (y<t) {
			t--;
			i++;
		}
		while (x<t) {
			t--;
			i--;
		}
		cout << i << "\n";
	     }
	     else {
		ll i = t*t-t+1;
		while (x<t) {
			t--;
			i++;
		}
		while (y<t) {
			t--;
			i--;
		}
		cout << i << "\n";
	     }


     }
}
