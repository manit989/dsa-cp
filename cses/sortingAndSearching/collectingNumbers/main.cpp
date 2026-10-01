#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

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

    cout << res << "\n";
    return 0;
}
