#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    if (n==3 || n==2) {
	    cout << "NO SOLUTION" << "\n";
	    return 0;
    }
    else if (n%2!=0) {
	cout << n-- << " ";
    }
    int a = n;
    int b = n/2;
    for (int i=0;i<n/2;i++) {
	    cout << b-- << " " << a-- << " ";
    }
    cout << "\n";

    return 0;
}
