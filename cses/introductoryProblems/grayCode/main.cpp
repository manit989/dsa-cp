#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    for (int i=0;i<pow(2,n);i++) {
	    string res = format("{:0{}b}",i^(i>>1),n);
	    cout << res << "\n";
    }
    return 0;
}
