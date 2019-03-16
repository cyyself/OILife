//https://acm.uestc.edu.cn/problem/c0ins/description
#include <bits/stdc++.h>
using namespace std;
int main() {
	int x,y;
	scanf("%d%d",&x,&y);
	if (x > y) swap(x,y);
	int flag = (x % 10 == 9 && y % 10 == 1);
	int ans = max(x,y) / 10;
	x %= 10;
	y %= 10;
	int cur = 0x3f3f3f3f;
	for (int c1=0;c1<=9;c1++) 
		for (int c2=0;c2<=4;c2++)
			for (int c5=0;c5<=1;c5++) {
				bool f[10];
				memset(f,0,sizeof(f));
				f[0] = 1;
				for (int i=0;i<c1;i++) for (int j=9;j>=1;j--) f[j] |= f[j-1];
				for (int i=0;i<c2;i++) for (int j=9;j>=2;j--) f[j] |= f[j-2];
				for (int i=0;i<c5;i++) for (int j=9;j>=5;j--) f[j] |= f[j-5];
				if (f[x] && f[y]) cur = min(cur,c1+c2+c5);
			}
	ans += cur;
	printf("%d\n",ans-flag);
	return 0;
}
