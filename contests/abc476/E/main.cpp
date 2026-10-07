#include <bits/stdc++.h>
#include <climits>
using namespace std;

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
#define vpin(v)                                                                \
  for (auto &x : v)                                                            \
  cin >> x.first >> x.second
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl "\n"
#define ff first
#define ss second

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

int n, m;

struct Node {
  pii mn;
  pii mx;
};

Node neutral() { return {{INT_MAX, -1}, {-1, -1}}; }
Node merge(Node a, Node b) { return {min(a.mn, b.mn), max(a.mx, b.mx)}; }

vector<Node> tree;

void update(int pos, int val) {
  pos += n;
  tree[pos] = {{val, pos - n}, {val, pos - n}};
  for (pos /= 2; pos >= 1; pos /= 2) {
    tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
  }
}

Node query(int l, int r) {
  Node res = neutral();
  for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
    if (l & 1)
      res = merge(res, tree[l++]);
    if (r & 1)
      res = merge(res, tree[--r]);
  }
  return res;
}

void solve() {
  cin >> n >> m;

  vi p(n);
  tree.assign(2 * n, neutral());
  f(i, 0, n) {
    cin >> p[i];
    update(i, p[i]);
  }

  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;

    Node ans = query(l, r);
    int min_idx = ans.mn.ss;
    int max_idx = ans.mx.ss;

    swap(p[min_idx], p[max_idx]);
    update(min_idx, p[min_idx]);
    update(max_idx, p[max_idx]);
  }

  for (auto x : p)
    cout << x << " ";
  cout << "\n";
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
