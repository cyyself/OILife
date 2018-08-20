#include <cstdio>
#include <cstring>
using namespace std;
int fa;
int num[10];
int f[10][4600];
int len;
//9个9的情况是4599
int dfs(int dep,int cur,bool uplimited) {
	if (cur < 0) return 0;
	if (dep == -1) return 1;
	else {
		if (!uplimited && f[dep][cur] != -1) return f[dep][cur];
		int up = 9;
		if (uplimited) up = num[dep];
		int ans = 0;
		for (int i=0;i<=up;i++) {
			ans += dfs(dep-1,cur - i*(1<<dep),uplimited && i == up);
		}
		if (!uplimited) f[dep][cur] = ans;
		return ans;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	memset(f,-1,sizeof(f));
	for (int c=1;c<=T;c++) {
		int a,b;
		scanf("%d%d",&a,&b);
		fa = 0;
		int zhishu = 0;//指数
		while (a) {
			fa += (a % 10) * (1 << zhishu);
			a /= 10;
			zhishu ++;
		}
		len = 0;
		while (b) {
			num[len++] = b % 10;
			b /= 10;
		}
		printf("Case #%d: %d\n",c,dfs(len-1,fa,true));
	}
	return 0;
}
