#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

int josephus(int n, int k) {
    int a = n > 1 ? (josephus(n-1, k) + k - 1) % n + 1 : 1;
    cout << a << "\n";
    return a;
}

int main() {
    fast_io;
    int n,k;
    cin >> n >> k;

    int res = 0;

    cout << josephus(n, k) << "\n";


    return 0;
}
