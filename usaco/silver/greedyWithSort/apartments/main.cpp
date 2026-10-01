#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     ll n,m,k;

     cin >> n >> m >> k;

     vector<ll> applicant(n);
     vector<ll> apartment(m);

     for (auto &x:applicant)	cin >> x;
     for (auto &x:apartment)	cin >> x;

     sort(apartment.begin(),apartment.end());
     sort(applicant.begin(),applicant.end());

     ll i=0,j=0,res=0;

     while (i<n && j<m) {
	     if (apartment[j]<applicant[i]-k)	j++;
	     else if (apartment[j]>=applicant[i]-k && apartment[j]<=applicant[i]+k) {
		     res++;
		     i++;
		     j++;
	     }
	     else	i++;
     }

     cout << res << endl;
}
