#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int u;
		scanf("%d",&u);
		map <char,int> cnt;
		set <char> impossible_zero;
		vector <pair<long long,string> > d;
		for (int i=1;i<=1e4;i++) {
			long long q;
			string r;
			cin >> q >> r;
			d.push_back(make_pair(q,r));
		}
		set <char> exist;
		for (int i=0;i<1e4;i++) {
			string r = d[i].second;
			if (r.length() == u) cnt[r[0]] ++;
			for (int j=0;j<r.length();j++) exist.insert(r[j]);
			if (r.length() > 1) impossible_zero.insert(r[0]);
		}
		char zero = '0';
		for (auto x:exist)if (impossible_zero.find(x) == impossible_zero.end()) {
			zero = x;
			break;
		}
		vector <pair<int,char> > ans;
		for (auto x:cnt) ans.push_back(make_pair(x.second,x.first));
		sort(ans.begin(),ans.end());
		reverse(ans.begin(),ans.end());
		//debug {
		//for (auto x:ans) cout << x.first << "\t" << x.second << "\n";
		//debug }
		printf("Case #%d: %c",cas,zero);
		for (auto x:ans) if (x.second != zero) printf("%c",x.second);
		printf("\n");
	}
	return 0;
}
