#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int bfs(int v,vector<int>& d,vector<bool>& m,vector<vector<int>>& t) {
	d[v]=0;
	queue<pair<int,int>> q;
	q.push({v,0});

	while (!q.empty()) {
		pair<int,int> vn = q.front();
		m[vn.first]=true;
		d[vn.first]=vn.second;
		q.pop();
		for (auto x:t[vn.first])	if (!m[x])	q.push({x,vn.second+1});
	}

	int fn = v;
	for (int i=0;i<d.size();i++) {
		if (d[i]>d[fn])	fn=i;
	}

	return fn;
}

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<vector<int>> t(n);
    for (int i=1;i<n;i++) {
	    int a,b;
	    cin >> a >> b;
	    a--;
	    b--;
	    t[a].push_back(b);
	    t[b].push_back(a);
    }
    vector<bool> m1(n);
    vector<bool> m2(n);
    vector<int> d(n);
    bfs(bfs(0,d,m1,t),d,m2,t);

    cout << *max_element(d.begin(),d.end()) << "\n";

 return 0;
}
