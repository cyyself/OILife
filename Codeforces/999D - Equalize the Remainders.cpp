#include <bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005];
int buzu[200005];
int buzur = 0;
int guoliang[200005];
int guoliangl = 0;
int guoliangr = 0;
queue <int> mem[200005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int need = n / m;
	for (int i=0;i<n;i++) {
		int mod = a[i] % m;
		c[mod] ++;
	}
	for (int i=0;i<m;i++) {
		if (c[i] < need) for (int j=0;j<need-c[i];j++) buzu[buzur++] = i;
		else for (int j=0;j<c[i]-need;j++)  guoliang[guoliangr++] = i;
	}
	sort(buzu,buzu+buzur);
	sort(guoliang,guoliang+guoliangr);
	long long ans = 0;
	for (int i=0;i<buzur;i++) {
		if (buzu[i] < guoliang[guoliangl]) {
			//从过量最大的选
			mem[guoliang[guoliangr-1]].push(buzu[i] + m - guoliang[guoliangr-1]);
			ans += buzu[i] + m - guoliang[guoliangr-1];
			guoliangr --;
		}
		else {
			//从过量最小的选
			mem[guoliang[guoliangl]].push(buzu[i] - guoliang[guoliangl]);
			ans += buzu[i] - guoliang[guoliangl];
			guoliangl ++;
		}
	}
	printf("%lld\n",ans);
	for (int i=0;i<n;i++) {
		if (!mem[a[i]%m].empty()) {
			int delta = mem[a[i]%m].front();
			mem[a[i]%m].pop();
			a[i] += delta;
		}
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}