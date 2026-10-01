#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);


     int n,m;
     cin >> n >> m;

     multiset<int> h;

     for (int i=0;i<n;i++) {
             int x;
             cin >> x;
             h.insert(x);
     }
     for (int i=0;i<m;i++) {
             int x;
             cin >> x;
             if (h.count(x)) {
                     cout << x << endl;
                     auto it = h.find(x);
                     h.erase(it);
             }
             else {
                     auto it = h.lower_bound(x);
                     if (h.empty())     cout << -1 << endl;
                     else {
                             if (it==h.begin()) cout << -1 << endl;
                             else {
                                     cout << *(--it) << endl;
                                     h.erase(it);
                             }
                     }
             }
     }

}
