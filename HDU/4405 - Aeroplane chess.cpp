#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const double base = 1.0 / 6.0;
int jump[MAXN];
double f[MAXN];//期望次数
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2 && n) {
		memset(jump,0,sizeof(jump));
		memset(f,0,sizeof(f));
		while (m --) {
			int x,y;
			scanf("%d%d",&x,&y);
			jump[x] = y;
		}
		for (int i=n-1;i>=0;i--) {
			if (jump[i]) f[i] = f[jump[i]];
			else {
				for (int j=1;j<=6;j++) f[i] += f[i+j] * base;
				f[i] += 1;
			}
		}
		printf("%0.4lf\n",f[0]);//为什么没有spj
	}
	return 0;
}
