#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpi vector<pii>
#define f(i,a,b) for(int i=a; i<b; i++)
#define fit(v) for (auto &x:v)
#define vin(v) for (auto &x:v)	cin >> x
#define vpin(v) for (auto &x:v)	cin >> x.first >> x.second
#define rf(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl "\n"
#define ff first
#define ss second

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#ifdef LOCAL
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

template<class T> void _print(T x) { cerr << x; }
template<class T, class V> void _print(pair<T,V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template<class T> void _print(vector<T> v) { cerr << "["; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

const int MOD = 998244353;
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


map<pii,int> f;
bool vis[1001];
vvi G(1001);

bool dfs(int s, int t) {
	if (s == t)	return true;
	vis[s] = true;
	for (auto x:G[s]) {
		if (!vis[x] && dfs(x, t)) {
			f[{min(s,x), max(s,x)}]++;
			return true;
		}
	}
	vis[s] = false;
	return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;


    vi a(m);
    vin(a);

    f (i,1,n) {
	int a, b;
	cin >> a >> b;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    f (i, 0, m-1) {
	    memset(vis, false, sizeof(vis));
	    dfs(a[i], a[i+1]);
    }

    int s = 0;
    for (auto x:f)	s += x.second;

    if ((s+k)%2 || (s+k<0)) {
	    cout << 0 << "\n";
	    return;
    }

    int r = (s+k)/2;
    vi dp(r+1, 0);
    dp[0] = 1;

    for (auto x:f) {
	    rf (i, r, 1) {
		    if (i-x.ss>=0) {
			    dp[i] = mod_add(dp[i], dp[i-x.ss]);
		    }
	    }
    }

    int res = dp[r];

    int untraversed = n - 1 - size(f);
    f (i, 0, untraversed) {
	    res = mod_mul(res, 2LL);
    }
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
    // cin >> t;
    while (t--) solve();

    return 0;
}
