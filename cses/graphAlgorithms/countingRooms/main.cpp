#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
 
void dfs(vector<string> &g,vector<vector<bool>> &visited,int i,int j) {
        if (i<0 || j<0 || i>=g.size() || j>=g[0].size() || visited[i][j] || g[i][j]=='#')       return;
        visited[i][j]=true;
        dfs(g,visited,i+1,j);
        dfs(g,visited,i-1,j);
        dfs(g,visited,i,j+1);
        dfs(g,visited,i,j-1);
}
 
int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
 
     int n,m;
     cin >> n >> m;
 
     vector<string> g;
     vector<vector<bool>> visited(n,vector<bool>(m,false));
 
     int res=0;
     
     for (int i=0;i<n;i++) {
             string x;
             cin >> x;
             g.push_back(x);
     }
 
     for (int i=0;i<n;i++) {
             for (int j=0;j<m;j++) {
                     if (g[i][j]=='.' && !visited[i][j]) {
                             res++;
                             dfs(g,visited,i,j);
                     }
             }
     }
 
     cout << res << endl;
}
