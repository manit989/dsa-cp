#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     vector<vector<int>> v(n,vector<int>(2));

     for (auto &x:v)    cin >> x[0] >> x[1];

     sort(all(v),[](auto &l,auto &r){
        return l[1]<r[1];
     });

     set<vector<int>> s;

     for (auto &x:v) {
        if (s.empty())  s.insert(x);
        
        else {
                vector<int> t = *s.rbegin();
                if ((x[0]>t[0] && x[0]<t[1]) || (t[0]>x[0] && t[0]<x[1]))   continue;
                else    s.insert(x);
        }
     }

     cout << (int)s.size() << endl;
}
