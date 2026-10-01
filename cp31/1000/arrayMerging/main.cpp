#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpi vector<pii>
#define f(j,a,b) for(int j=a; j<b; j++)
#define fit(v) for (auto &x:v)
#define vin(v) for (auto &x:v)  cin >> x
#define rf(j,a,b) for(int j=a; j>=b; j--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl "\n"

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#ifdef LOCAL
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

template<class T> void _print(T x) { cerr << x; }
template<class T, class V> void _print(pair<T,V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<class T> void _print(vector<T> v) { cerr << "["; for (auto j : v) { _print(j); cerr << " "; } cerr << "]"; }

const int MOD = 1000000007;
const int INF = 1000000000000000000LL;

int mod_add(int a, int b) { return (a % MOD + b % MOD) % MOD; }
int mod_sub(int a, int b) { return (a % MOD - b % MOD + MOD) % MOD; }
int mod_mul(int a, int b) { return (a % MOD * b % MOD) % MOD; }
int mod_pow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}
int mod_inv(int a) { return mod_pow(a, MOD - 2); }

struct DSU {
    vi parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        f(j, 0, n) parent[j] = j;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) swap(xr, yr);
        parent[yr] = xr;
        if (rank[xr] == rank[yr]) rank[xr]++;
        return true;
    }
};

void bfs(int start, vi adj[], vi &vis) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int child : adj[node]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

vi sieve(int n) {
    vi isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int j = 2; j*j <= n; j++) {
        if (isPrime[j]) {
            for (int k = j*j; k <= n; k += j) isPrime[k] = 0;
        }
    }
    return isPrime;
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solve() {
    int n;
    cin >> n;
    
    vi a(n),b(n);
    vin(a);
    vin(b);

    vi va(2*n+1,0LL);
    vi vb(2*n+1,0LL);

    int curr_num = -1;
    int curr_freq = 1;
    for (auto x:a) {
	if (x==curr_num)	curr_freq++;
	else {
		curr_num = x;
		curr_freq = 1;
	}
	va[x]=max(va[x],curr_freq);
    }
    curr_num = -1;
    curr_freq = 1;
    for (auto x:b) {
	if (x==curr_num)	curr_freq++;
	else {
		curr_num = x;
		curr_freq = 1;
	}
	vb[x]=max(vb[x],curr_freq);
    }

    int res=0;
    for (int i=1;i<=2*n;i++)	res=max(res,va[i]+vb[i]);

    cout << res << "\n";


}

int32_t main() {
    fastio();

#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
