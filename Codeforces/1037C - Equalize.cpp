#include <bits/stdc++.h>
using namespace std;
char a[1000005];
char b[1000005];
bool need[1000005];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s%s",a,b);
	for (int i=0;i<n;i++) need[i] = a[i] != b[i];
	int cost = 0;
	for (int i=0;i<n-1;i++) {
		if (need[i] && need[i+1] && a[i] != a[i+1]) {
			need[ i ] = false;
			need[i+1] = false;
			cost ++;
		}
	}
	for (int i=0;i<n;i++) cost += need[i];
	printf("%d\n",cost);
	return 0;
}
