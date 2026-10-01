#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> v(n);
    for (auto &x:v)	cin >> x;
    
    map<ll,vector<pair<int,int>>> m;
    for (int i=0;i<n;i++) {
	for (int j=i+1;j<n;j++) {
		m[v[i]+v[j]].push_back({i,j});
	}
    }


    for (int i=0;i<n;i++) {
	for (int j=i+1;j<n;j++) {
		if (m.count(t-(v[i]+v[j]))) {
			for (auto x:m[t-(v[i]+v[j])]) {
				if (i!=x.first && i!=x.second && j!=x.first && j!=x.second) {
					cout << i+1  << " " << j+1 << " " << x.first+1 << " " << x.second+1 << "\n";
					return 0;
				}
			}
		}
	}
    }

    cout << "IMPOSSIBLE" << "\n";

    return 0;
}
