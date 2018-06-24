#include <bits/stdc++.h>
using namespace std;
char s[100005];
vector <int> p[3];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		p[0].clear();
		p[1].clear();
		p[2].clear();
		scanf("%s",s);
		int len = strlen(s);
		for (int i=0;i<len;i++) {
			char c = toupper(s[i]);
			switch(c) {
				case 'A':
					p[0].push_back(i);
					break;
				case 'C':
					p[1].push_back(i);
					break;
				case 'M':
					p[2].push_back(i);
					break;
			}
		}
		int ans = 0;
		for (vector<int>::iterator it=p[0].begin();it != p[0].end();it++) {
			vector<int>::iterator b = upper_bound(p[1].begin(),p[1].end(),*it);
			if (b == p[1].end()) continue;
			vector<int>::iterator c = upper_bound(p[2].begin(),p[2].end(),*b);
			if (c == p[2].end()) continue;
			ans ++;
			p[1].erase(b);
			p[2].erase(c);
		}
		printf("%d\n",ans);
	}

	return 0;
}
