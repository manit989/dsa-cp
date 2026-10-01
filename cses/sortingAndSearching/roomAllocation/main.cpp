#include <bits/stdc++.h>
#include <queue>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
 
int main() {
    fast_io;
    int n;
    cin >> n;
 
    map<pair<int,int>,int> m;
    vector<int> res(n);
    int it = 0;
    vector<vector<int>> v(n,vector<int>(3));
    for (auto &x:v) {
	    cin >> x[0] >> x[1];
	    x[2]=it++;
    }
 
 
    sort(v.begin(),v.end());
 
    int curr_room = 1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 
    for (auto x:v) {
	    if (pq.empty() || pq.top().first>=x[0]) {
		    res[x[2]]=curr_room;
		    pq.push({x[1],curr_room++});
	    }
	    else {
		    pair<int,int> p = pq.top();
		    pq.pop();
		    res[x[2]]=p.second; 
		    pq.push({x[1],p.second});
	    }
    }
 
    cout << curr_room-1 << "\n";
    for (auto x:res)	cout << x << " ";
    cout << "\n";
 
    return 0;
}

