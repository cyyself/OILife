#include <bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		scanf("%s",a);
		scanf("%s",b);
		int last = -1;
		vector <pair<int,int> > all;
		for (int i=0;i<n+1;i++) {
			if (a[i] == b[i]) {
				if (last != -1) all.push_back(make_pair(last,i-1));
				last = -1;
			}
			else {
				if (last == -1) last = i;
			}
		}
		
		//debug
		//for (auto x:all) cout << x.first << "\t" << x.second << endl;
		//debug
		int k=all.size();
		if(k==0) {
			printf("%lld\n",1LL*n*(n+1)/2);
		}
		else if(k==1) {
			printf("%lld\n",2LL*(all[0].second-all[0].first)+2LL*(n-(all[0].second-all[0].first+1)));
		}
		else if(k==2) {
			printf("6\n");
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}
