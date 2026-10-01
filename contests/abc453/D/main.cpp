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

string ans;
map<pii,int> mo;
map<pii,int> mx;

void search(int x,int y,bool& pf,string& path,vector<string>& g,vector<vector<bool>>& m) {
	if (pf || x<0 || x>=size(g) || y<0 || y>=size(g[0]) || g[x][y]=='#' || (m[x][y] && (g[x][y]=='.' || g[x][y]=='S' || (g[x][y]=='o' && mo[{x,y}]==4) || (g[x][y]=='x' && mx[{x,y}]==4)))) {
		return;
	}
	m[x][y]=true;
	if (g[x][y]=='G') {
		pf=true;
		ans=path;
	}
	else if (g[x][y]=='.' || g[x][y]=='S') {
		path.push_back('U');
		search(x-1,y,pf,path,g,m);
		path.pop_back();
		path.push_back('D');
		search(x+1,y,pf,path,g,m);
		path.pop_back();
		path.push_back('L');
		search(x,y-1,pf,path,g,m);
		path.pop_back();
		path.push_back('R');
		search(x,y+1,pf,path,g,m);
		path.pop_back();
	}
	else if (g[x][y]=='o') {
		if (path.back()=='U') {
			mo[{x,y}]++;
			path.push_back('U');
			search(x-1,y,pf,path,g,m);
			path.pop_back();
		}
		else if (path.back()=='D') {
			mo[{x,y}]++;
			path.push_back('D');
			search(x+1,y,pf,path,g,m);
			path.pop_back();
		}
		else if (path.back()=='L') {
			mo[{x,y}]++;
			path.push_back('L');
			search(x,y-1,pf,path,g,m);
			path.pop_back();
		} 
		else {
			mo[{x,y}]++;
			path.push_back('R');
			search(x,y+1,pf,path,g,m);
			path.pop_back();
		}
	}
	else if (g[x][y]=='x') {
		if (path.back()=='U' || path.back()=='D') {
			mx[{x,y}]+=2;
			path.push_back('R');
			search(x,y+1,pf,path,g,m);
			path.pop_back();
			path.push_back('L');
			search(x,y-1,pf,path,g,m);
			path.pop_back();
		}
		else {
			mx[{x,y}]+=2;
			path.push_back('U');
			search(x-1,y,pf,path,g,m);
			path.pop_back();
			path.push_back('D');
			search(x+1,y,pf,path,g,m);
			path.pop_back();
		}
	}
	m[x][y]=false;
}

void solve() {
    int h,w;
    cin >> h >> w;

    vector<string> g(h);
    vin(g);

    vector<vector<bool>> m(h,vector<bool>(w));
    bool pf = false;
    string path = "";

    int x,y;
    bool fd = false;
    for (int i=0;i<h && !fd;i++) {
	    for(int j=0;j<w && !fd;j++) {
		    if (g[i][j]=='S') {
			    x=i;
			    y=j;
			    fd=true;
		    }
	    }
    }

    search(x,y,pf,path,g,m);

    cout << (pf ? "Yes\n"+ans : "No") << "\n";
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
