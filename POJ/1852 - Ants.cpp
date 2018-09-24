#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while (t --) {
		int l,n;
		scanf("%d%d",&l,&n);
		int MIN = 0;
		int MAX = 0;
		for (int i=0;i<n;i++) {
			int pos;
			scanf("%d",&pos);
			MIN = max(MIN,min(pos,l-pos));
			MAX = max(MAX,max(pos,l-pos));
		}
		printf("%d %d\n",MIN,MAX);
	}
	return 0;
}
