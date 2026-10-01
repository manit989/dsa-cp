#include <bits/stdc++.h>
using namespace std;
#define n 8
vector<string> cows = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
map<string,int> id = {{"Beatrice",0},{"Belinda",1},{"Bella",2},{"Bessie",3},{"Betsy",4},{"Blue",5},{"Buttercup",6},{"Sue",7}};
map<int,string> name = {{0,"Beatrice"},{1,"Belinda"},{2,"Bella"},{3,"Bessie"},{4,"Betsy"},{5,"Blue"},{6,"Buttercup"},{7,"Sue"}};


vector<vector<string>> perm;
void solve(vector<string> lineup,vector<bool>& added) {
	if (lineup.size()==n) {
		perm.push_back(lineup);
		return;
	}
	for (auto x:cows) {
		if (added[id[x]])	continue;
		added[id[x]]=true;
		lineup.push_back(x);
		solve(lineup,added);
		added[id[x]]=false;
		lineup.pop_back();
	}
}

int loc(const vector<string> &order, const string &cow) {
	return find(order.begin(), order.end(), cow) - order.begin();
}

int main() {
     freopen("lineup.in", "r", stdin);
     freopen("lineup.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     string z;

     vector<vector<string>> cnst;

     int m;
     cin >> m;
     for (int i=0;i<m;i++) {
	     string a;
	     string b;
	     cin >> a >> z >> z >> z >> z >> b;
	     cnst.push_back({a,b});
     }

     vector<bool> added(n,false);
     vector<int> lineup;

     solve({},added);

     for (auto x:perm) {
	     bool b = true;
	     for (auto y:cnst) {
		     if (abs(loc(x,y[0])-loc(x,y[1]))>1)	b=false;
	     }
	     if (b) {
		     for (auto y:x)	cout << y << endl;
		     return 0;
	     }
     }

}
