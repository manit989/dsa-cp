#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n,d;
    cin >> d >> n;

    vector<int> v(n);
    for (auto &x:v)	cin >> x;

    set<int> s = {0,d};
    multiset<int> res = {d};

    for (auto x:v) {
	    auto lit = --s.upper_bound(x);
	    auto git = s.upper_bound(x);
	    int dt = *git - *lit;
	    auto it = res.find(dt);
	    res.erase(it);
	    res.insert(x-*lit);
	    res.insert(*git-x);
	    s.insert(x);
	    cout << *res.rbegin() << " ";
    }

    cout << "\n";
    return 0;
}
