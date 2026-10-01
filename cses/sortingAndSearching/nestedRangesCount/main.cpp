#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define rng pair<int,int>

int main() {
    fast_io;
    int n;
    cin >> n;

    vector<rng> v(n);
    map<rng,int> m;
    map<int,int> cc;
    set<int> c;
    for (int i=0;i<n;i++) {
	    cin >> v[i].first >> v[i].second;
	    m[v[i]]=i;
	    c.insert(v[i].second);
    }
    int k=1;
    for (auto x:c)	cc[x]=k++;

    sort(v.begin(),v.end(),[](auto &l,auto &r){
	return (l.first==r.first) ? l.second > r.second : l.first<r.first;
    });

    vector<int> containsTree(c.size()+1,0);
    vector<int> isContainedTree(c.size()+1,0);

    vector<int> contains(n,0);
    vector<int> isContained(n,0);

    for (int i=n-1;i>=0;i--) {
	    int a=cc[v[i].second];
	    int s = 0;
	    while (a>=1) {
		    s+=containsTree[a];
		    a-=a&-a;
	    }
	    contains[m[v[i]]]=s;
	    a=cc[v[i].second];
	    while (a<=cc.size()) {
		    containsTree[a]+=1;
		    a+=a&-a;

	    }
    }

    for (int i=0;i<n;i++) {
	    int a=cc[v[i].second]-1;
	    int s=0;
	    while (a>=1) {
		    s+=isContainedTree[a];
		    a-=a&-a;
	    }
	    isContained[m[v[i]]]=i-s;
	    a=cc[v[i].second];
	    while (a<=cc.size()) {
		    isContainedTree[a]+=1;
		    a+=a&-a;

	    }

    }

    for (auto x:contains)	cout << x << " ";
    cout << "\n";
    for (auto x:isContained)	cout << x << " ";
    cout << "\n";

    return 0;
}
