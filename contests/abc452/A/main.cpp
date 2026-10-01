#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long


int main() {
    fast_io;
    int m,d;
    cin >> m >> d;

    set<pair<int,int>> fd = {{1,7},{3,3},{5,5},{7,7},{9,9}};

    if (fd.count({m,d})) {
	    cout << "Yes" << "\n";
    }
    else {
	    cout << "No" << "\n";
    }


    return 0;
}
