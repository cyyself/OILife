#include <bits/stdc++.h>
using namespace std;
int s[105];//n=9时只有89个 
int f[10][105][85];
inline bool judgex(int s) {
	if (s & (s << 1)) return false;
	return true;
}
inline int cnt(int s) {
	int ret = 0;
	while (s) {
		if (s & 1) ret ++;
		s = s >> 1;
	}
	return ret;
}
inline bool judgey(int sa,int sb) {
	if (sa & sb) return false;
	return true;
}
inline bool judgep(int sa,int sb) {//判断倾斜 
	if (sa & (sb << 1)) return false;
	if ((sa << 1) & sb) return false;
	return true;
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int scnt = 0;
	for (int i=0;i<(1<<n);i++) if (judgex(i)) s[scnt++] = i;
	for (int i=0;i<scnt;i++) f[0][i][cnt(s[i])] = 1;
	for (int i=1;i<n;i++) 
		for (int j=0;j<scnt;j++) {
			int jcnt = cnt(s[j]);
			for (int l=0;l<scnt;l++) {
				if (judgep(s[j],s[l]) && judgey(s[j],s[l])) {
					for (int m=cnt(s[l]);m<=k-jcnt;m++) f[i][j][m+jcnt] += f[i-1][l][m];
				}
			}
		}
	int ans = 0;
	for (int i=0;i<scnt;i++) ans += f[n-1][i][k];
	printf("%d\n",ans);
	return 0;
}
