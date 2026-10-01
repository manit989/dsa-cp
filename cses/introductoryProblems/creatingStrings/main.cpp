#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

set<string> res;

void dfs(string& b,string& s,vector<bool>& v) {
	if (b.size()==s.size()) {
		string a;
		for (auto x:b)	a.push_back(x);
		res.insert(a);
		return;
	}
	for (int i=0;i<s.size();i++) {
		if (v[i])	continue;
		b.push_back(s[i]);
		v[i]=true;
		dfs(b,s,v);
		v[i]=false;
		b.pop_back();
	}
}

int main() {
    fast_io;
    string s;
    cin >> s;

    int n=s.size();
    string b;
    vector<bool> v(n);

    dfs(b,s,v);

    cout << res.size() << "\n";
    for (auto x:res) {
	    cout << x << "\n";
    }

    return 0;
}
