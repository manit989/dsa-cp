#include <algorithm>
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

void solve() {
  int n, m;
  cin >> n >> m;

  vi p;
  f(i, 1, n + 1) p.push_back(i);

  set<pii> tkshi;
  set<pii> aoki;

  f(i, 0, m) {
    int a, b;
    cin >> a >> b;

    tkshi.insert({a, b});
  }
  f(i, 0, m) {
    int c, d;
    cin >> c >> d;

    aoki.insert({c, d});
  }

  do {
    bool b = true;
    f(i, 1, n + 1) {
      f(j, i + 1, n + 1) {
        if (tkshi.count({i, j}) !=
            aoki.count({min(p[i - 1], p[j - 1]), max(p[i - 1], p[j - 1])})) {
          b = false;
          break;
        }
      }
      if (!b)
        break;
    }

    if (b) {
      cout << "Yes\n";
      return;
    }
  } while (next_permutation(all(p)));

  cout << "No\n";
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
