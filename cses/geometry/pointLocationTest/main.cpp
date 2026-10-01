#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    double x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double value = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);

    if (value==0) {
	    cout << "TOUCH\n";
    }
    else if (value<0) {
	    cout << "RIGHT\n";
    }
    else {
	    cout << "LEFT\n";
    }

}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
