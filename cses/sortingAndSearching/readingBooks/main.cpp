#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int main() {
    fast_io;
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (auto &x:a)
	    cin >> x;

    ll maxTime = *max_element(a.begin(),a.end());
    ll restTime = accumulate(a.begin(),a.end(),0LL)-maxTime;

    if (maxTime>restTime) {
	    cout << 2*maxTime << "\n";
    }
    else {
	    cout << restTime+maxTime << "\n";
    }

    return 0;
}
