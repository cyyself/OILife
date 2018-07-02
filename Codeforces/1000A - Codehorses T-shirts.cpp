#include <bits/stdc++.h>
using namespace std;
map <string,int> mem;
int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		string t;
		cin >> t;
		mem[t] ++;
	}
	int ans = 0;
	for (int i=0;i<n;i++) {
		string t;
		cin >> t;
		if (mem[t] > 0) mem[t] --;
		else ans ++;
	}
	printf("%d\n",ans);
	return 0;
}