#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("teleport.in","r",stdin);
	freopen("teleport.out", "w", stdout);
	int start, end, x, y;
	scanf("%d %d %d %d",&start,&end,&x,&y);
	int dist = abs(start-end);
	if (dist > abs(start-x) + abs(end-y))	dist = abs(start-x) + abs(end-y);
	if (dist > abs(start-y) + abs(end-x))	dist = abs(start-y) + abs(end-x);
	cout << dist;
}
