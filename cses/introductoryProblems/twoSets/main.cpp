#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    if ((n%2 ? (n+1)/2 : n/2)%2) {
	    cout << "NO" << "\n";
	    return 0;
    }

    cout << "YES" << "\n";
    cout << n/2 << "\n";
    for (int i=1;i<=(n/4);i++)	cout << i << " ";
    for (int i=n;i>=n/4+1+(n-n/2);i--)	cout << i << " ";
    cout << "\n";

    cout << n-n/2 << "\n";
    for (int i=(n/4)+1;i<n/4+1+(n-n/2);i++)	cout << i << " ";
    cout << "\n";

    
    return 0;
}
