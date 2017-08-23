#include <cstdio>
int n,k;
int a[25];
int cnt = 0;
bool judge(int x) {
	if (x == 0) return false;
	for (int i=2;i*i<=x;i++) if (x % i == 0) return false;
	return true;
}
void DFS(int depth,int last,int tot) {
	if (depth == 0) {
		if (judge(tot)) cnt ++;
	}
	else {
		for (int i=last+1;i<n;i++) {
			int nn = tot + a[i];
			DFS(depth-1,i,nn);
		}
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	DFS(k,-1,0);
	printf("%d\n",cnt);
	return 0;
}