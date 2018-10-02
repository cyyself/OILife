#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair <int,int> s[5005];
pair <int,int> l[5005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&s[i].first,&s[i].second);
		sort(s,s+n);
		int line = 0;
		for (int i=0;i<n;i++) {
			bool flag = false;
			for (int j=0;j<line && !flag;j++) 
				if (l[j].first <= s[i].first && l[j].second <= s[i].second) {
					l[j] = s[i];
					flag = true;
				}
			if (!flag) {
				l[line++] = s[i];
			}
		}
		printf("%d\n",line);
	}
	return 0;
}
