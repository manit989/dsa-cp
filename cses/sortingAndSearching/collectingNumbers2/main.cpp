#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
vector<pair<int,int>> d = {{-1,0},{0,1}};

int main() {
    fast_io;
    int n,m;
    cin >> n >> m;

    vector<int> v(n);
    for (auto &x:v)	cin >> x;


    vector<int> pos(n+1);
    for (int i=0;i<n;i++) {
	    pos[v[i]]=i;
    }

    int res=1;
    int curr_pos = pos[1];
    int i=1;
    while (i<n) {
	if (pos[i+1]<curr_pos) {
		res++;
	}
	curr_pos=pos[i+1];
	i++;
    }

    for (int i=0;i<m;i++) {
	    int a,b;
	    cin >> a >> b;
	    a--;
	    b--;
	    set<pair<int,int>> s;
	    for (auto [g,h]:d) {
		    if (v[a]+g>=1 && v[a]+h<=n)	s.insert({v[a]+g,v[a]+h});
		    if (v[b]+g>=1 && v[b]+h<=n)	s.insert({v[b]+g,v[b]+h});
	    }
	    for (auto [j,k]:s)	if (pos[j]>pos[k])	res--;
	    pos[v[a]]=b;
	    pos[v[b]]=a;
	    int t = v[a];
	    v[a]=v[b];
	    v[b]=t;
	    for (auto [j,k]:s)	if (pos[j]>pos[k])	res++;
	    cout << res << "\n";
    }

    return 0;
}
