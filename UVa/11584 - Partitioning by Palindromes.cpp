#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1005];
bool judge(int begin,int end) {
	while (begin < end) {
		if (s[begin] != s[end]) return false;
		begin ++;
		end --;
	}
	return true;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%s",&s[1]);
		unsigned int f[1005];
		memset(f,0xff,sizeof(f));//赋值最大值，无符号int直接赋值全1即可
		f[0] = 0;
		for (int i=1;i<=strlen(&s[1]);i++) {
			for (int j=1;j<=i;j++) {
				if (judge(j,i)) f[i] = min(f[i],f[j-1]+1);//看看从合并从j到i的字符为一个比较小还是不划分比较小
			}
		}
		printf("%d\n",f[strlen(&s[1])]);//因为之前数组已经后移一位，因此去除的strlen不必-1
	}
	return 0;
}