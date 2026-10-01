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

void solve() {
    int h,w;
    cin >> h >> w;

    vector<string> v(h);
    vin(v);

    vector<string> g(h,string(w,'.'));

    vector<vi> dir = {{1,1},{-1,-1},{1,-1},{-1,1},{0,1},{1,0},{0,-1},{-1,0}};
    auto val = [&](int x,int y){return (x>=0 && x<h && y>=0 && y<w);};

    for (int i=0;i<h;i++) {
	    for (int j=0;j<w;j++) {
		    for (auto x:dir) {
			    if (v[i][j] == '.') {
				    if (val(i + x[0], j + x[1]) && v[i+x[0]][j+x[1]] == '#') {
					    g[i][j] = '#';
					    break;
				    }
			    }
		    }
	    }
    }
    v = move(g);

    vector<vi> D(h,vi(w,INF));
    queue<pii> q;
    f (i,0,h) {
	    f (j,0,w) {
		    if (v[i][j] == '#') {
			    D[i][j] = 0;
			    q.push({i,j});
		    }
	    }
    }
    while (!q.empty()) {
	    auto [i,j] = q.front();q.pop();
	    for (auto x:dir) {
		    int m = i+x[0], n = j+x[1];
		    if (val(m, n) && D[m][n] == INF) {
			    D[m][n] = 1 + D[i][j];
			    q.push({m,n});
		    }
	    }
    }

    for (auto &x:D) {
	    for (auto y:x)	cout << (y%2 ? '#' : '.');
	    cout << "\n";
    }

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
