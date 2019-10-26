#include <bits/stdc++.h>
using namespace std;
struct UnionSet {
	int f[1005];
	void init(int m) {
		for (int i=1;i<=m+2;i++) f[i] = i;
	}
	int find(int x) {
		if (f[x] != x) f[x] = find(f[x]);
		return f[x];
	}
	void uni(int x,int y) {
		f[find(x)] = find(y);
	}
}line[1005];
int n,m;
int id(int x,int y) {
	return (x-1) * m + y - 1;
}
struct UnionSet2 {
	int f[1000005];
	void init() {
		for (int i=0;i<n*m;i++) f[i] = i;
	}
	int find(int x) {
		if (f[x] != x) f[x] = find(f[x]);
		return f[x];
	}
	void uni(int x,int y) {
		f[find(x)] = find(y);
	}
}u;
char s[1005][1005];
int ans;
void insert(int x,int y) {
	ans ++;
	line[x].uni(y,y+1);
	s[x][y] = '1';
	vector <int> st;
	if (y + 1 <= m && s[x][y+1] == '1') st.push_back(u.find(id(x,y+1)));
	if (x + 1 <= n && s[x+1][y] == '1') st.push_back(u.find(id(x+1,y)));
	if (x - 1 >= 1 && s[x-1][y] == '1') st.push_back(u.find(id(x-1,y)));
	if (y - 1 >= 1 && s[x][y-1] == '1') st.push_back(u.find(id(x,y-1)));
	for (auto each:st) {
		if (u.find(each) != u.find(id(x,y))) {
			u.uni(each,id(x,y));
			ans --;
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	u.init();
	for (int i=1;i<=n;i++) {
		scanf("%s",&s[i][1]);
		line[i].init(m);
		for (int j=m;j>=1;j--) if (s[i][j] == '1') insert(i,j);
	}
	int q;
	scanf("%d",&q);
	while (q --) {
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for (int x=x1;x<=x2;x++) {
			for (int y=line[x].find(y1);y<=y2;y=line[x].find(y+1)) {
				insert(x,y);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
