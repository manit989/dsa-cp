#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
  int n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;

  vi a(n);
  vi b(m);
  vin(a);
  vin(b);

  sort(all(a));
  sort(all(b));

  int res = 0;

  vi pkb(m + 1, 0);
  f(i, 1, m + 1) { pkb[i] = pkb[i - 1] + (b[i - 1] + k - 1) / k; }

  vi pmb(m + 1, 0);
  f(i, 1, m + 1) { pmb[i] = pmb[i - 1] + b[i - 1]; }

  vi pa(n + 1, 0);
  f(i, 1, n + 1) { pa[i] = pa[i - 1] + a[i - 1]; }

  f(d, 0, m + 1) {
    if (pkb[d] <= y && pmb[d] <= x + y * k) {
      int w = x + y * k - pmb[d];
      res = max(res, d + distance(pa.begin(), upper_bound(all(pa), w)) - 1);
    }
  };

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
  while (t--)
    solve();

  return 0;
}
