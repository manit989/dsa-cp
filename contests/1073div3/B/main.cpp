#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x:v) {
	    cin >> x;
    }

    vector<int> res(n);
    int currstart=n-1;
    int currend=n-1;
    int mstart=n-1;
    int mend=n-1;

    for (int i=n-1;i>=0;i--) {
	    if (i==currstart)	continue;
	    else if (v[i]<v[currstart]) {
		    currend=i;
		    if (mstart-mend<currstart-currend || v[currstart]>v[mstart]) {
			    mstart=currstart;
			    mend=currend;
		    }
	    }
	    else {
		    currstart=i;
		    currend=i;
	    }
    }


    for (int i=0;i<mend;i++) {
	    res[i]=v[i];
    }
    int j=mend;
    for (int i=mstart;i>=mend;i--,j++) {
	    res[i]=v[j];
    }
    for (int i=mstart+1;i<n;i++) {
	    res[i]=v[i];
    }

    for (auto x:res)	cout << x << " ";
    cout << endl;



    
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
