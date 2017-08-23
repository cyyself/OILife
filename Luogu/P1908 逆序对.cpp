#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct shuju {
	int pos,value;
	friend bool operator < (const shuju &a,const shuju &b){
		if (a.value < b.value) return true;
		else return false;
	}
}a[40005];
int lowbit(int x) {
	return x&(-x);
}
int s[40005];
int ls[40005];
int ans = 0;
void add(int x) {
	for (int i=x;i<=n;i+=lowbit(i)) s[i] ++;
}
void find(int x) {
	for (int i=x;i>0;i-=lowbit(i)) ans += s[i];
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i].value);
		a[i].pos = i;
	}
	sort(a+1,a+n+1);
	int lsx = 1;//离散序
	for (int i=1;i<=n;i++) {//离散化
		if (i != 1 && a[i].value != a[i-1].value) lsx ++;
		ls[a[i].pos] = lsx;
	}
	for (int i=n;i>=1;i--) {
		add(ls[i]);
		find(ls[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}