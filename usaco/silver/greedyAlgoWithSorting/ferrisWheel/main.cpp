#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll n,x;
     cin >> n >> x;

     vector<ll> v(n);

     for (auto &y:v)    cin >> y;
     sort(all(v));

     ll res=0;

     int l=0,r=n-1;

     while (l<r) {
             if (v[l]+v[r]<=x) {
                     res++;
                     l++;
                     r--;
             }
             else {
                     res++;
                     r--;
             }
     }
     if (l==r)  res++;
     

     cout << res << endl;
}
