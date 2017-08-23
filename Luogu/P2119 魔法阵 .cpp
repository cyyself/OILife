#include <cstdio>
#include <algorithm>
using namespace std;
struct object {
	int num;
	int pos;
};
int n,m;
int x[15005];
int ca[15005];
int cb[15005];
int cc[15005];
int cd[15005];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&x[i]);
	for (int a=1;a<=m;a++)
		for (int b=1;b<=m;b++) {
			if (x[a] < x[b]) 
				for (int c=1;c<=m;c++) {
					if (x[b] < x[c] && x[b]-x[a] < (double)(x[c]-x[b])/ 3)
						for (int d=1;d<=m;d++) {
							if (x[c] < x[d] && x[b]-x[a] == 2*(x[d]-x[c])) {
								ca[a] ++;
								cb[b] ++;
								cc[c] ++;
								cd[d] ++;
							}
						}
				}
		}
	for (int i=1;i<=m;i++) printf("%d %d %d %d\n",ca[i],cb[i],cc[i],cd[i]);
	return 0;
}