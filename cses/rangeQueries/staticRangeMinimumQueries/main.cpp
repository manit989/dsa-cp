#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n,q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &x:v)	cin >> x;

    int len = (int) sqrt(n + .0) + 1;
    vector<int> b(len,INT_MAX);
    for (int i=0;i<n;i++)	b[i/len]=min(b[i/len],v[i]);
    
    while (q--) {
	    int l,r;
	    cin >> l >> r;
	    l--;
	    r--;

	    int res = INT_MAX;
	    int cl = l/len, cr = r/len;
	    if (cl==cr) {
		    for (int i=l;i<=r;i++)	res=min(res,v[i]);
	    }
	    else {
		    for (int i=l, end=(cl+1)*len-1;i<=end;++i)	res=min(res,v[i]);
		    for (int i=cl+1;i<=cr-1;++i)	res=min(res,b[i]);
		    for (int i=cr*len;i<=r;i++)	res=min(res,v[i]);
	    }
	    cout << res << "\n";
    }


    return 0;
}
