#include <bits/stdc++.h>
using namespace std;
char s[55];
int len;
bool type[26];
int pre_v_min[55];
int pre_v_max[55];
int pre_c_min[55];
int pre_c_max[55];
int suf_v_min[55];
int suf_v_max[55];
int suf_c_min[55];
int suf_c_max[55];
bool dfs(int dep,int v,int c) {
	if (v >= 3 || c >= 5) return false;
	if (dep == len) return true;
	bool stat = false;
	if (s[dep] == '?') {
		if (c < 4) stat |= dfs(dep+1,0,c+1);
		if (!stat && v < 2) stat |=  dfs(dep+1,v+1,0);
	}
	else {
		if (type[s[dep]-'A']) stat |= dfs(dep+1,v+1,0);
		else stat |= dfs(dep+1,0,c+1);
	}
	return stat;
}
int main() {
	type['A'-'A'] = true;
	type['E'-'A'] = true;
	type['I'-'A'] = true;
	type['O'-'A'] = true;
	type['U'-'A'] = true;
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(pre_v_min,0,sizeof(pre_v_min));
		memset(pre_v_max,0,sizeof(pre_v_max));
		memset(pre_c_min,0,sizeof(pre_c_min));
		memset(pre_c_max,0,sizeof(pre_c_max));
		memset(suf_v_min,0,sizeof(suf_v_min));
		memset(suf_v_max,0,sizeof(suf_v_max));
		memset(suf_c_min,0,sizeof(suf_c_min));
		memset(suf_c_max,0,sizeof(suf_c_max));
		scanf("%s",s);
		len = strlen(s);
		bool bad = false;
		bool mixed = false;
		// prefix {
		if (s[0] == '?') {
			pre_v_max[0] = 1;
			pre_c_max[0] = 1;
		}
		else {
			if (type[s[0]-'A']) {
				pre_v_min[0] = 1;
				pre_v_max[0] = 1;
			}
			else {
				pre_c_min[0] = 1;
				pre_c_max[0] = 1;
			}
		}
		for (int i=1;i<len;i++) {
			if (s[i] == '?') {
				pre_v_max[i] = pre_v_max[i-1] + 1;
				pre_v_min[i] = 0;
				pre_c_max[i] = pre_c_max[i-1] + 1;
				pre_c_min[i] = 0;
			}
			else {
				if (type[s[i]-'A']) {
					//vowels
					pre_c_min[i] = 0;
					pre_c_max[i] = 0;
					pre_v_min[i] = pre_v_min[i-1] + 1;
					pre_v_max[i] = pre_v_max[i-1]+1;
				}
				else {
					pre_v_min[i] = 0;
					pre_v_max[i] = 0;
					pre_c_min[i] = pre_c_min[i-1] + 1;
					pre_c_max[i] = pre_c_max[i-1] + 1;
				}
			}
			if (pre_v_min[i] >= 3 || pre_c_min[i] >= 5) bad = true;
			if (pre_v_max[i] >= 3 || pre_c_max[i] >= 5) mixed = true;
		}
		// prefix }
		// suffix {
		if (s[len-1] == '?') {
			suf_v_max[len-1] = 1;
			suf_c_max[len-1] = 1;
		}
		else {
			if (type[s[len-1]-'A']) {
				suf_v_min[len-1] = 1;
				suf_v_max[len-1] = 1;
			}
			else {
				suf_c_min[len-1] = 1;
				suf_c_max[len-1] = 1;
			}
		}
		for (int i=len-2;i>=0;i--) {
			if (s[i] == '?') {
				suf_v_max[i] = suf_v_max[i+1] + 1;
				suf_v_min[i] = 0;
				suf_c_max[i] = suf_c_max[i+1] + 1;
				suf_c_min[i] = 0;
			}
			else {
				if (type[s[i]-'A']) {
					//vowels
					suf_c_min[i] = 0;
					suf_c_max[i] = 0;
					suf_v_min[i] = suf_v_min[i+1] + 1;
					suf_v_max[i] = suf_v_max[i+1]+1;
				}
				else {
					suf_v_min[i] = 0;
					suf_v_max[i] = 0;
					suf_c_min[i] = suf_c_min[i+1] + 1;
					suf_c_max[i] = suf_c_max[i+1] + 1;
				}
			}
			if (s[i] == '?') {
				if (pre_v_min[i-1] >= 2 && suf_c_min[i+1] >= 4) bad = true;
				if (suf_v_min[i+1] >= 2 && pre_c_min[i-1] >= 4) bad = true;
			}
		}
		// suffix }
		if (bad) printf("Case %d: BAD\n",c);
		else {
			if (mixed) {
				if (dfs(0,0,0)) printf("Case %d: MIXED\n",c);
				else printf("Case %d: BAD\n",c);
			}
			else printf("Case %d: GOOD\n",c);
		}
	}
	return 0;
}
