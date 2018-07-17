#include <bits/stdc++.h>
using namespace std;
int a[1005];
vector< pair<int,int> > m[200000];
int n;
int main() {
	int s;
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) for (int j=0;j<i;j++) m[a[i]+a[j]].push_back(make_pair(j,i));//j < i
	int ans = 0;
	for (int i=0;i<n;i++)
		for (int j=0;j<i;j++) {
			int sum = a[i] + a[j];
			int need = s - sum;
			for (auto e:m[need]) {
				if (e.first > i) ans ++;
			}
		}
	printf("%d\n",ans);
	return 0;
}
