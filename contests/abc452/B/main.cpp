#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int r,c;
    cin >> r >> c;
    for (int i=0;i<c;i++)	cout << "#";
    cout << "\n";
    for (int i=1;i<r-1;i++) {
	    cout << "#";
    	    for (int i=1;i<c-1;i++)	cout << ".";
	    cout << "#\n";
    }
    for (int i=0;i<c;i++)	cout << "#";
    cout << "\n";
    return 0;
}
