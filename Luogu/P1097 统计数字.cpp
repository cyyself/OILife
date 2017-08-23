#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int last = a[0];
	int cnt = 1;
	for (int i=1;i<n;i++){
		if (a[i] == last) cnt ++;
		else {
			printf("%d %d\n",last,cnt);
			last = a[i];
			cnt = 1;
		}
	}
	printf("%d %d\n",last,cnt);
	return 0;
}