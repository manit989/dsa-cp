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

int h,w;
vector<string> G;

vector<vi> dir = {{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(int x,int y) {
	if (x<0 || x>=h || y<0 || y>=w)	return false;
	return true;
}

int bfs(int x,int y) {
	vector<vi> d(h,vi(w,1e9));
	deque<pii> dq;

	d[x][y] = 0;
	dq.push_front({x,y});

	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	while (!dq.empty()) {
		auto [a,b] = dq.front();
		dq.pop_front();

		f (i,0,4) {
			if (isValid(a+dx[i], b+dy[i]) && G[a+dx[i]][b+dy[i]]=='.' && d[a+dx[i]][b+dy[i]] > d[a][b]) {
				d[a+dx[i]][b+dy[i]] = d[a][b];
				dq.push_front({a+dx[i],b+dy[i]});
			}
		}

		f (i,-2,3) {
			f (j,-2,3) {
				if (abs(i)==2 && abs(j)==2)	continue;

				if (isValid(a+i, b+j) && d[a+i][b+j]>d[a][b]+1) {
					d[a+i][b+j] = d[a][b] + 1;
					dq.push_back({a+i,b+j});
				}
			}
		}
	}

	return d[h-1][w-1];
}

void solve() {
	cin >> h >> w;
	G.resize(h);

	for (auto &x:G)	cin >> x;

	cout << bfs(0,0) << "\n";
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
