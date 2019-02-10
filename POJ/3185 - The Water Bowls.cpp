#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[20];
int c[20];
int work1() {
	memcpy(c,a,sizeof(c));
	int res = 1;
	c[0] ^= 1;
	c[1] ^= 1;
	for (int i=1;i<20;i++) {
		if (c[i-1]) {
			res ++;
			c[i-1] ^= 1;
			c[ i ] ^= 1;
			c[i+1] ^= 1;
		}
	}
	if (c[19]) return 0x3f3f3f3f;
	return res;
}
int work2() {
	memcpy(c,a,sizeof(c));
	int res = 0;
	for (int i=1;i<20;i++) {
		if (c[i-1]) {
			res ++;
			c[i-1] ^= 1;
			c[ i ] ^= 1;
			c[i+1] ^= 1;
		}
	}
	if (c[19]) return 0x3f3f3f3f;
	return res;
}
int main() {
	for (int i=0;i<20;i++) scanf("%d",&a[i]);
	printf("%d\n",min(work1(),work2()));
	return 0;
}
