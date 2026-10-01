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

    int res = 1;
    int l = 0;
    map<int,int> m;

    for (int i=0;i<n;i++) {
	    if (m.count(v[i]) && m[v[i]]>=l) {
		    l=min(m[v[i]]+1,i);
	    }
	    m[v[i]]=i;
	    res=max(res,i-l+1);
    }

    cout << res << "\n";
    return 0;
}
