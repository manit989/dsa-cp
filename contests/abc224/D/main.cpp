#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpi vector<pii>
#define f(i, a, b) for (int i = a; i < b; i++)
#define fit(v) for (auto &x : v)
#define vin(v)                                                                 \
  for (auto &x : v)                                                            \
  cin >> x
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl "\n"

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

#ifdef LOCAL
#define dbg(x)                                                                 \
  cerr << #x << " = ";                                                         \
  _print(x);                                                                   \
  cerr << endl;
#else
#define dbg(x)
#endif

template <class T> void _print(T x) { cerr << x; }
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

const int MOD = 1000000007;
const int INF = 1000000000000000000LL;

int mod_add(int a, int b) { return (a % MOD + b % MOD) % MOD; }
int mod_sub(int a, int b) { return (a % MOD - b % MOD + MOD) % MOD; }
int mod_mul(int a, int b) { return (a % MOD * b % MOD) % MOD; }
int mod_pow(int a, int b) {
  int res = 1;
  a %= MOD;
  while (b) {
    if (b & 1)
      res = mod_mul(res, a);
    a = mod_mul(a, a);
    b >>= 1;
  }
  return res;
}
int mod_inv(int a) { return mod_pow(a, MOD - 2); }

int C(int n, int k) {
  if (k < 0 || k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  int num = 1, den = 1;
  for (int i = 1; i <= k; i++) {
    num = mod_mul(num, (n - i + 1) % MOD);
    den = mod_mul(den, i);
  }
  return mod_mul(num, mod_inv(den));
}
struct DSU {
  vi parent, rank;
  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    f(i, 0, n) parent[i] = i;
  }
  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  bool unite(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr)
      return false;
    if (rank[xr] < rank[yr])
      swap(xr, yr);
    parent[yr] = xr;
    if (rank[xr] == rank[yr])
      rank[xr]++;
    return true;
  }
};

void bfs(int start, vi adj[], vi &vis) {
  queue<int> q;
  q.push(start);
  vis[start] = 1;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int child : adj[node]) {
      if (!vis[child]) {
        vis[child] = 1;
        q.push(child);
      }
    }
  }
}

void solve() {
  int m;
  cin >> m;

  string v = "0123456780";
  string u = "0000000000";

  vpi e(m);
  for (auto &x : e)
    cin >> x.first >> x.second;

  f(i, 1, 9) {
    int a;
    cin >> a;
    u[a] = i + '0';
  }

  map<string, int> vis;
  queue<pair<string, int>> q;
  vis[u] = 0;
  q.push({u, 0});

  while (!q.empty()) {
    auto [p, d] = q.front();
    q.pop();

    for (auto &x : e) {
      auto [i, j] = x;
      if ((p[i] == '0') != (p[j] == '0')) {
        string t = p;
        swap(t[i], t[j]);

        if (!vis.count(t) || (vis[t] > d + 1)) {
          vis[t] = d + 1;
          q.push({t, d + 1});
        }
      }
    }
  }

  cout << (vis.count(v) ? vis[v] : -1) << "\n";
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
  while (t--)
    solve();

  return 0;
}
