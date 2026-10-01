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
#define rf(i,a,b) for(int i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl "\n"

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MOD = 998244353;

int mod_add(int a, int b) { return (a % MOD + b % MOD) % MOD; }

int dp[1024][1024][10] = {0};

void solve() {
    int n;
    string s;
    cin >> n >> s;

    f (i,1,n+1) {
	    int x = s[i-1] - 'A';
	    f (j,0,1024) {
		    f (k,0,10) {
			    dp[i][j][k] = dp[i-1][j][k];
			    if (k == x)	dp[i][j][k] = mod_add(dp[i][j][k], dp[i-1][j][k]);
		    }
	    }

	    f (j,0,1024) {
		    if (j&(1<<x))	continue;
		    f (k,0,10) {
			    dp[i][j | (1<<x)][x] = mod_add(dp[i][j | (1<<x)][x], dp[i-1][j][k]);
		    }
	    }
	    dp[i][(1<<x)][x] = mod_add(dp[i][(1<<x)][x], 1LL);
    }

    int res = 0;
    f (j,0,1024) {
	    f (k,0,10) {
		    res = mod_add(res, dp[n][j][k]);
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
