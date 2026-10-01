#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    int n;
    cin >> n;

    queue<int> q;
    for (int i=1;i<=n;i++) {
	    q.push(i);
    }

    bool pass = true;
    while (!q.empty()) {
	    if (pass) {
		    int a = q.front();
		    q.pop();
		    q.push(a);
	    }
	    else {
		    int a = q.front();
		    q.pop();
		    cout << a << " ";
	    }
	    pass = !(pass);
    }
    cout << "\n";

    return 0;
}
