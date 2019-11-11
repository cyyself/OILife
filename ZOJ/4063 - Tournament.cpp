/*
#include <bits/stdc++.h>
using namespace std;
bool used[16][16];
bool u[1000][16][16];
int main() {
	int n;
	scanf("%d",&n);
	int p[16];
	for (int i=0;i<n;i++) p[i] = i;
	int cnt = 0;
	do {
		bool ok = true;
		for (int i=0;i<n;i++) if (p[i] == i || p[p[i]] != i) ok = false;
		for (int i=0;i<n;i++) if (used[i][p[i]]) ok = false;
		for (int a=0;a<n;a++) {
			int c = p[a];
			for (int i=0;i<cnt;i++) for (int b=0;b<n;b++) for (int d=0;d<n;d++) if (u[i][a][b] && u[i][c][d] && p[b] != d) {
				ok = false;
			}
		}
		if (!ok) continue;
		for (int i=0;i<n;i++) {
			used[i][p[i]] = true;
			u[cnt][i][p[i]] = true;
		}
		cnt ++;
		for (int i=0;i<n;i++) printf("%d ",p[i]+1);
		printf("\n");
		fflush(stdout);
	}
	while (next_permutation(p,p+n));
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) {
	return x & (-x);
}
int mt[1024][1024];
void change(int *src,int *dst,int bs,int sz) {
	for (int i=0;i<sz;i+=bs) {
		memcpy(dst+i,src+i,bs*sizeof(int));
		reverse(dst+i,dst+i+bs);
	}
}
int main() {
	for (int i=0;i<1024;i+=2) mt[0][i] = 2 + i;
	for (int i=1;i<1024;i+=2) mt[0][i] = i;
	for (int i=1;i<1023;i++) change(mt[i-1],mt[i],lowbit(i+1)<<1,1024);
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		if (k >= lowbit(n)) printf("Impossible\n");
		else {
			for (int i=0;i<k;i++) {
				for (int j=0;j<n;j++) printf("%d%c",mt[i][j],j==n-1?'\n':' ');
			}
		}
	}
	return 0;
}
