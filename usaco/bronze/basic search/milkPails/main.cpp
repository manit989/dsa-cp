#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int x,int y,int m,int* res,set<int>& s) {
	if (s.count(m))	return;
	if (m<x) {
		*res=min(*res,m);
		return;
	}
	s.insert(m);
	solve(x,y,m-x,res,s);
	if (m>=y)	solve(x,y,m-y,res,s);
}

int main() {
     freopen("pails.in", "r", stdin);
     freopen("pails.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     int x,y,m;
     cin >> x >> y >> m;
     int res = INT_MAX;
     set<int> s;

     solve(x,y,m,&res,s);

     cout << m-res;
}
