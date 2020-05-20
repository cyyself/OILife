#include <bits/stdc++.h>
using namespace std;
int k[10];
map <string,int> f;
map <int,string> rev;
string tmp;
int win[3] = {2,0,1};
int lose[3] = {1,2,0};
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&k[i]);
	int ptr = 0;
	int cnt = 0;
	f["ChuiZi"] = 0;
	rev[0] = "ChuiZi";
	f["JianDao"] = 1;
	rev[1] = "JianDao";
	f["Bu"] = 2;
	rev[2] = "Bu";
	while (cin >> tmp) {
		if (tmp == "End") break;
		int cur = f[tmp];
		if (cnt < k[ptr]) {
			cout << rev[win[cur]] << endl;
			cnt ++;
		}
		else {
			cout << rev[lose[cur]] << endl;
			cnt = 0;
			ptr = (ptr + 1) % n;
		}
	}
	return 0;
}
