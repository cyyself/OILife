//这道题难点在于如何处理才能不算前缀的0
#include <cstdio>
#include <cstring>
using namespace std;
int f[32][32][32];
int num[32];
int len;
int dfs(int dep,int cnt0,int cnt1,bool lim,bool exist1) {
	if (dep == -1) {
		return (cnt0 >= cnt1 || exist1 == false);
	}
	else {
		if (!lim && f[dep][cnt0][cnt1] != -1) return f[dep][cnt0][cnt1];
		int ans = 0;
		int up = 1;
		if (lim) up = num[dep];
		for (int i=0;i<=up;i++) {
			if (exist1 || i == 1) ans += dfs(dep-1,cnt0+(i == 0),cnt1+(i == 1),lim && i == up,true);
			else ans += dfs(dep-1,0,0,lim && i == up,false);
		}
		if (!lim) f[dep][cnt0][cnt1] = ans;
		return ans;
	}
}
int solve(int x) {
	len = 0;
	while (x) {
		num[len++] = x & 1;
		x >>= 1;
	}
	return dfs(len-1,0,0,true,false);
}
int main() {
	memset(f,-1,sizeof(f));
	int l,r;
	scanf("%d%d",&l,&r);
	int ans = solve(r);
	ans -= solve(l-1);
	printf("%d\n",ans);
	return 0;
}
