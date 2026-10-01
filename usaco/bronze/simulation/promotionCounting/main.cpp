#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     freopen("promote.in", "r", stdin);
     freopen("promote.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll bb=0,ba=0,sb=0,sa=0,gb=0,ga=0,pb=0,pa=0;

     cin >> bb >> ba;
     cin >> sb >> sa;
     cin >> gb >> ga;
     cin >> pb >> pa;

     ll b2s=pa-pb+ga-gb+sa-sb,s2g=pa-pb+ga-gb,g2p=pa-pb;

     cout << b2s << endl;
     cout << s2g << endl;
     cout << g2p << endl;


}
