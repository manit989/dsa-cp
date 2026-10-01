#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;

void solve() {
        int n,h,l;
        cin >> n >> h >> l;

        vector<int> v;

        for (int i=0;i<n;i++) {
                int x;
                cin >> x;
                if (x>h && x>l) continue;
                v.push_back(x);
        }

        n=(int)v.size();
        int res;

        int hv=0;
        int lv=0;

        for (int i=0;i<n;i++)   if (v[i]<=h && v[i]>l)  hv++;
        for (int i=0;i<n;i++)   if (v[i]<=l && v[i]>h)  lv++;

        res = min(hv,lv);

        if (abs(hv-lv)>n-hv-lv) res+=min(abs(hv-lv),n-hv-lv);
        else    res+=((abs(hv-lv)+n-hv-lv)/2);

        cout << res << endl;

}

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;
     while (n--)        solve();
}
