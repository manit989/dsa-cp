#include <bits/stdc++.h>
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

void solve() {
  int m;
  cin >> m;

  int u, v;
  vi G[10];
  f(i, 0, m) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int p;
  string s = "999999999";
  f(i, 1, 9) {
    cin >> p;
    s[p - 1] = i + '0';
  }

  queue<string> Q;
  Q.push(s);
  map<string, int> mp;
  mp[s] = 0;

  while (!Q.empty()) {
    string s = Q.front();
    Q.pop();
    f(i, 1, 10) if (s[i - 1] == '9') v = i;

    for (auto u : G[v]) {
      string t = s;
      swap(t[u - 1], t[v - 1]);
      if (mp.count(t))
        continue;
      mp[t] = mp[s] + 1;
      Q.push(t);
    }
  }

  if (mp.count("123456789") == 0)
    cout << -1 << endl;
  else
    cout << mp["123456789"] << endl;
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
