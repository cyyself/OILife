#include <bits/stdc++.h>
using namespace std;
int ans;
int num[14];//3->0,4->1,10->7,J->8,K->10,A->11,2->12,鬼->13
void DFS(int depth,int cur) {
	if (depth >= ans) return;
	ans = min(ans,cur+depth);
	
	//四带二或炸弹 {
	for (int i=0;i<14;i++) if (num[i] >= 4) {
		num[i] -= 4;
		//炸弹
		DFS(depth+1,cur-4);
		//带2单
		for (int j=0;j<14;j++) if (num[j] >= 1) {
			num[j] --;
			for (int k=0;k<14;k++) if (num[k] >= 1) {
				num[k] --;
				DFS(depth+1,cur-6);
				num[k] ++;
			}
			num[j] ++;
		}
		//带2对
		for (int j=0;j<14;j++) if (num[j] >= 2) {
			num[j] -= 2;
			for (int k=0;k<14;k++) if (num[k] >= 2) {
				num[k] -=2;
				DFS(depth+1,cur-8);
				num[k] += 2;
			}
			num[j] +=2;
		}
		num[i] += 4;
	}
	//4带2或炸弹}
	//三顺子{
	for (int i=0;i<11;i++) if (num[i] >= 3) {
		num[i] -= 3;
		int last = i;
		for (int j=i+1;j<12 && num[j] >= 3;j++) {
			last = j;
			num[j] -= 3;
			DFS(depth+1,cur - (j-i+1) * 3);
		}
		for (int j=i;j<=last;j++) num[j] += 3;
	}
	//三顺子}
	//双顺子{
	for (int i=0;i<10;i++) if (num[i] >= 2 && num[i+1] >= 2) {
		num[i] -= 2;
		num[i+1] -= 2;
		int last = i+1;
		for (int j=i+2;j< 12 && num[j] >= 2;j++) {
			last = j;
			num[j] -= 2;
			DFS(depth+1,cur - (j-i+1) * 2);
		}
		for (int j=i;j<=last;j++) num[j] += 2;
	}
	//双顺子}
	
	//单顺子{
	for (int i=0;i<8;i++) if (num[i] > 0 && num[i+1] > 0 && num[i+2] > 0 && num[i+3] > 0) {
		num[i] --;
		num[i+1] --;
		num[i+2] --;
		num[i+3] --;
		int last = i + 3;
		for (int j=i+4;j<12 && num[j] > 0;j++) {
			last = j;
			num[j] --;
			DFS(depth+1,cur - (j-i+1));
		}
		for (int j=i;j<=last;j++) num[j] ++;
	}
	//单顺子}	
	
	//三带2 & 三带1 & 三张牌{
	for (int i=0;i<14;i++) if (num[i] >= 3) {
		num[i] -= 3;
		//三张牌
		DFS(depth+1,cur - 3);
		//三带1
		for (int j=0;j<14;j++) {
			if (i == j || num[j] <= 0) continue;
			num[j] --;
			DFS(depth+1,cur -4);
			if (num[j] > 0) {
				num[j] --;
				DFS(depth+1,cur - 5);
				num[j] ++;
			}
			num[j] ++;
		}
		num[i] += 3;
	}
	//三带2 & 三带1 & 三张牌}
	
	//对子 && 火箭{
	for (int i=0;i<14;i++) if (num[i] >= 2) {
		num[i] -= 2;
		DFS(depth+1,cur - 2);
		num[i] += 2;
	}
	//对子 && 火箭}
}
int main() {
	int T,n;
	scanf("%d%d",&T,&n);
	while (T--) {
		memset(num,0,sizeof(num));
		ans = n;
		for (int i=0;i<n;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			switch (a) {
				case 0:
					num[13] ++;
					break;
				case 1:
					num[11] ++;
					break;
				case 2:
					num[12] ++;
					break;
				default:
					num[a - 3] ++;
					break;
			}
		}
		DFS(0,n);
		printf("%d\n",ans);
	}
	return 0;
}