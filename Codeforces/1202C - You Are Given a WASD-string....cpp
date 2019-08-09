#include <bits/stdc++.h>
using namespace std;
char s[200005];
int pre[200005][4],suf[200005][4];
int pos[200005][4];
int len;
void init() {
	int x=0,y=0;
	for (int i=1;i<=len;i++) {
		if (s[i] == 'W') x ++;
		else if (s[i] == 'S') x --;
		else if (s[i] == 'A') y --;
		else y ++;
		pos[i][0] = x;
		pos[i][1] = y;
	}
	for (int i=1;i<=len;i++) {
		pre[i][0] = min(pre[i-1][0],pos[i][0]);
		pre[i][1] = max(pre[i-1][1],pos[i][0]);
		pre[i][2] = min(pre[i-1][2],pos[i][1]);
		pre[i][3] = max(pre[i-1][3],pos[i][1]);
	}
	suf[len+1][0] = suf[len+1][1] = pos[len][0];
	suf[len+1][2] = suf[len+1][3] = pos[len][1];
	for (int i=len;i>=1;i--) {
		suf[i][0] = min(suf[i+1][0],pos[i-1][0]);
		suf[i][1] = max(suf[i+1][1],pos[i-1][0]);
		suf[i][2] = min(suf[i+1][2],pos[i-1][1]);
		suf[i][3] = max(suf[i+1][3],pos[i-1][1]);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s",s+1);
		len = strlen(s+1);
		init();
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i=1;i<=len;i++) {
			long long h,w;
			//case1
			h = max(suf[i+1][1]+1,pre[i][1]) - min(suf[i+1][0]+1,pre[i][0]) + 1;
			w = max(suf[i+1][3],pre[i][3]) - min(suf[i+1][2],pre[i][2]) + 1;
			ans = min(ans,h*w);
			//case2
			h = max(suf[i+1][1]-1,pre[i][1]) - min(suf[i+1][0]-1,pre[i][0]) + 1;
			w = max(suf[i+1][3],pre[i][3]) - min(suf[i+1][2],pre[i][2]) + 1;
			ans = min(ans,h*w);
			//case3
			h = max(suf[i+1][1],pre[i][1]) - min(suf[i+1][0],pre[i][0]) + 1;
			w = max(suf[i+1][3]+1,pre[i][3]) - min(suf[i+1][2]+1,pre[i][2]) + 1;
			ans = min(ans,h*w);
			//case4
			h = max(suf[i+1][1],pre[i][1]) - min(suf[i+1][0],pre[i][0]) + 1;
			w = max(suf[i+1][3]-1,pre[i][3]) - min(suf[i+1][2]-1,pre[i][2]) + 1;
			ans = min(ans,h*w);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
