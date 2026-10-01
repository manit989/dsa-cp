#include <bits/stdc++.h>
using namespace std;

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
        f(i, 0, n) parent[i] = i;
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

vi sieve(int n) {
    vi isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i*i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i) isPrime[j] = 0;
        }
    }
    return isPrime;
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solve() {
    int n,k;
    cin >> n >> k;

    int res = 0;

    map<int,int> m;
    f (i,0,n) {
	int x;
	cin >> x;
	m[x]++;
    }

    while (k>0 && !m.empty()) {
	int c = m.rbegin()->first;
	int cf = m.rbegin()->second;

	if (size(m) == 1) {

		if (k >= c * cf) {
			res += (c * (c + 1) * cf) / 2;
			m.erase(c);
		}

		else {
			int f = k / cf;
			res += (((2 * c - f + 1) * f)/ 2) * cf;
			res += (c - f) * (k - f * cf);
			k = 0;
		}
	}

	else {
		m.erase(c);
		int sc = m.rbegin()->first;

		if ( k >= (c - sc) * cf) {
			k -= (c - sc) * cf;
			res += ((c - sc) * (c + sc + 1) * cf)/2;
			m[sc] += cf;
		}

		else {
			int f = k / cf;
			res += (((2 * c - f + 1) * f)/ 2) * cf;
			res += (c - f) * (k - f * cf);
			k = 0;
		}
	
	}
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
