#include <bits/stdc++.h>
using namespace std;
double dp[14][14][14][14][5][5];//四种花色的数量和鬼牌的选择
int aa,bb,cc,dd;
double dfs(int a,int b,int c,int d,int e,int f) {
	int aaa = a + (e == 1) + (f == 1);
	int bbb = b + (e == 2) + (f == 2);
	int ccc = c + (e == 3) + (f == 3);
	int ddd = d + (e == 4) + (f == 4);
	if (max(0,aa - aaa) + max(0,bb - bbb) + max(0,cc - ccc) + max(0,dd - ddd) == 0) return 0;
	if (dp[a][b][c][d][e][f] != 0) return dp[a][b][c][d][e][f];
	int rema = 13 - a, remb = 13 - b, remc = 13 - c, remd = 13 - d, remgui = (e == 0) + (f == 0);
	int remall = rema + remb + remc + remd + remgui;
	double &res = dp[a][b][c][d][e][f];
	if (rema) res += (dfs(a+1,b,c,d,e,f) + 1) * rema / remall;
	if (remb) res += (dfs(a,b+1,c,d,e,f) + 1) * remb / remall;
	if (remc) res += (dfs(a,b,c+1,d,e,f) + 1) * remc / remall;
	if (remd) res += (dfs(a,b,c,d+1,e,f) + 1) * remd / remall;
	if (remgui) {
		if (e == 0) {
			if (aa > 13) res += (dfs(a,b,c,d,1,f) + 1) * remgui / remall;
			else if (bb > 13) res += (dfs(a,b,c,d,2,f) + 1) * remgui / remall;
			else if (cc > 13) res += (dfs(a,b,c,d,3,f) + 1) * remgui / remall;
			else if (dd > 13) res += (dfs(a,b,c,d,4,f) + 1) * remgui / remall;
			else {
				double tmp = 1e18;
				if (aa - aaa > 0) tmp = min(tmp,(dfs(a,b,c,d,1,f) + 1) * remgui / remall); 
				if (bb - bbb > 0) tmp = min(tmp,(dfs(a,b,c,d,2,f) + 1) * remgui / remall);
				if (cc - ccc > 0) tmp = min(tmp,(dfs(a,b,c,d,3,f) + 1) * remgui / remall);
				if (dd - ddd > 0) tmp = min(tmp,(dfs(a,b,c,d,4,f) + 1) * remgui / remall);
				res += tmp;
			}
		}
		else {
			if (aa > 14) res += (dfs(a,b,c,d,e,1) + 1) * remgui / remall;
			else if (bb > 14) res += (dfs(a,b,c,d,e,2) + 1) * remgui / remall;
			else if (cc > 14) res += (dfs(a,b,c,d,e,3) + 1) * remgui / remall;
			else if (dd > 14) res += (dfs(a,b,c,d,e,4) + 1) * remgui / remall;
			else {
				if (aa > 13 && e != 1) res += (dfs(a,b,c,d,e,1) + 1) * remgui / remall;
				else if (bb > 13 && e != 2) res += (dfs(a,b,c,d,e,2) + 1) * remgui / remall;
				else if (cc > 13 && e != 3) res += (dfs(a,b,c,d,e,3) + 1) * remgui / remall;
				else if (dd > 13 && e != 4) res += (dfs(a,b,c,d,e,4) + 1) * remgui / remall;
				else {
					double tmp = 1e18;
					if (aa - aaa > 0) tmp = min(tmp,(dfs(a,b,c,d,e,1) + 1) * remgui / remall); 
					if (bb - bbb > 0) tmp = min(tmp,(dfs(a,b,c,d,e,2) + 1) * remgui / remall);
					if (cc - ccc > 0) tmp = min(tmp,(dfs(a,b,c,d,e,3) + 1) * remgui / remall);
					if (dd - ddd > 0) tmp = min(tmp,(dfs(a,b,c,d,e,4) + 1) * remgui / remall);
					res += tmp;
				}
			}
		}
	}
	return res;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
		int need = 0;
		need += max(0,aa-13) + max(0,bb-13) + max(0,cc-13) + max(0,dd-13);
		if (need > 2) printf("Case %d: -1\n",cas);
		else printf("Case %d: %0.10f\n",cas,dfs(0,0,0,0,0,0));
	}
	return 0;
}
