#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x:v)	cin >> x;

    multiset<int> s;
    for (auto x:v) {
	    auto it = s.upper_bound(x);
	    if (it != s.end()) {
		    s.erase(it);
		    s.insert(x);
	    }
	    else {
		    s.insert(x);
	    }

    }


    cout << (int)s.size() << "\n";
    return 0;
}

