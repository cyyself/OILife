#include <bits/stdc++.h>
using namespace std;
struct pic {
	string poem[105];
	int next;
}p[1005];
map <string,int> mem;
string t;
bool link[1005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	getline(cin,t);// skip \n
	if (m == 1) {//坑
		for (int i=1;i<=n;i++) {
			getline(cin,t);
			cout << t << endl;
		}
	}
	else {
		for (int i=1;i<=n;i++) {
			for (int j=0;j<m;j++) getline(cin,p[i].poem[j]);
			mem[p[i].poem[0]] = i;
		}
		for (int i=1;i<=n;i++) {
			p[i].next = mem[p[i].poem[m-1]];
			link[p[i].next] = true;
		}
		int head = 0;
		for (int i=1;i<=n;i++) if (!link[i]) head = i;
		cout << p[head].poem[0] << endl;
		while (head != 0) {
			for (int j=1;j<m;j++) cout << p[head].poem[j] << endl;
			head = p[head].next;
		}
	}
	return 0;
}
