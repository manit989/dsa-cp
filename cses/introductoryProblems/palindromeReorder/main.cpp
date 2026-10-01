#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    string s;
    cin >> s;

    int n = s.size();
    map<char,int> m;
    
    for (auto x:s)	m[x]++;

    string a;
    string b;
    string p;

    for (char c='A';c<='Z';c++) {
	    if (m[c]%2) {
		    b.push_back(c);
	    }
	    for  (int j=0;j<m[c]/2;j++) {
		    p.push_back(c);
		    a.push_back(c);
	    }
    }

    reverse(p.begin(),p.end());
    if (b.size()>1)	cout << "NO SOLUTION" << "\n";
    else	cout << a+b+p << "\n";

    return 0;
}
