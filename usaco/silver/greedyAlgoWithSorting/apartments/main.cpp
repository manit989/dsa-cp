#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll n,m,k;
     cin >> n >> m >> k;

     vector<ll> dsz(n);
     vector<ll> sz(m);

     for (auto &x:dsz)  cin >> x;
     for (auto &x:sz)  cin >> x;


     sort(all(dsz));
     sort(all(sz));

     int j=0,res=0;
     
     for (int i=0;i<n && j<n;i++) {
        if (sz[j]<dsz[i]-k)     j++;
        else if (sz[j]>dsz[i]+k)        continue;
        else {
                j++;
                res++;
        }
     }

     cout << res;
}
