#include <bits/stdc++.h>
#include <climits>
#include <numeric>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void dfs(int i,vector<ll>& v,ll* currsum,ll* sum,ll* res) {
	if (i==v.size()) {
		*res=min(*res,abs(*sum-2**currsum));
		return;
	}
	dfs(i+1,v,currsum,sum,res);
	*currsum+=v[i];
	dfs(i+1,v,currsum,sum,res);
	*currsum-=v[i];

}

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &x:v)	cin >> x;

    ll res = LLONG_MAX;
    ll sum = accumulate(v.begin(),v.end(),0LL);
    ll currsum = 0;

    dfs(0,v,&currsum,&sum,&res);

    cout << res << "\n";
    return 0;
}
