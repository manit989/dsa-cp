#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> perm;
set<int> s;

void solve(int n) {
	if (perm.size()==n) {
		for (auto x:perm)	cout << x << " ";
		exit(0);
	}
	for (auto x:s) {
		if (perm.empty() || abs(perm[perm.size()-1] - x)!=1) {
			perm.push_back(x);
			s.erase(x);
			solve(n);
			s.insert(x);
			perm.pop_back();
		}
	}
}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     if (n==2 || n==3) {
	     cout << "NO SOLUTION" << "\n";
	     return 0;
     }

     for (int i=1;i<=n;i++)	s.insert(i);

     solve(n);

}
