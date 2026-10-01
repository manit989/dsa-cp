#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100;

int main() {
     freopen("speeding.in", "r", stdin);
     freopen("speeding.out", "w", stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll n,m,res=0;

     cin >> n >> m;
	
     int prev = 1;
     vector<int> sgmnt(101);
     for (int i=0;i<n;i++) {
	     int send,sl;
	     cin >> send >> sl;
	     for (int i=0;i<send;i++)	sgmnt[prev+i]=sl;
	     prev+=send;
     }

	
     prev = 1;
     vector<int> bsgmnt(101);
     for (int i=0;i<m;i++) {
	     int send,sl;
	     cin >> send >> sl;
	     for (int i=0;i<send;i++)	bsgmnt[prev+i]=sl;
	     prev+=send;
     }

     for (int i=1;i<=100;i++)	res=max((int)res,bsgmnt[i]-sgmnt[i]);

     cout << res << "\n";
}
