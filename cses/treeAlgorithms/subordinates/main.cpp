#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int dfs(vector<vector<int>> &g,vector<int>& res,int v) {
	for (auto x:g[v])	res[v]+=dfs(g,res,x);
	return 1+res[v];
}

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);

    for (int i=2;i<=n;i++) {
	    int x;
	    cin >> x;
	    if (i==1)	continue;
	    else {
		    g[x].push_back(i);
	    }
    }
    vector<int> res(n+1,0);
    
    dfs(g,res,1);

    for (int i=1;i<=n;i++)	cout << res[i] << " ";
    cout << "\n";

    return 0;
}
