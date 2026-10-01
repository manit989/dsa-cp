#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    int res=0;
    int i=1;
    while (n>=pow(5,i)) {
	    res+=n/pow(5,i);
	    i++;
    }

    cout << res << "\n";
    return 0;
}
