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

const int MOD = 1 << 20;
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

int N = 1 << 20;

void solve() {
  int q;
  cin >> q;

  int t, x;
  set<int> s;
  map<int, int> m;

  f(i, 0, N) {
    s.insert(i);
    m[i] = -1;
  }

  f(i, 0, q) {
    cin >> t >> x;
    int h = x % N;

    if (t == 1) {
      if (m[h] == -1) {
        s.erase(h);
        m[h] = x;
      } else {
        auto it = s.upper_bound(h);
        it = (it == s.end() ? s.begin() : it);
        m[*it] = x;
        s.erase(it);
      }
    } else {
      cout << m[h] << "\n";
    }
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
  while (t--)
    solve();

  return 0;
}
