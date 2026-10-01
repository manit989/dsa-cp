#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     vector<int> arr(7);
     
     for (int i=0;i<7;i++)	cin >> arr[i];

     sort(arr.begin(),arr.end());

     int a,b,c;
     
     c = arr[6] - arr[0] - arr[1];
     b = arr[6] - arr[0] - c;
     a = arr[6] - b - c;

     cout << a << " " << b << " " << c;
}
