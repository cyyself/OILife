#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s",s);
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		int a = 0;
		for (int i=0;s[i] != 0;i++) {
			if (cnt[s[i]-'a'] == 0) a ++;
			cnt[s[i]-'a'] ++;
		}
		vector <pair<char,int> > mem;
		for (int i=0;i<26;i++) if (cnt[i]) mem.push_back(make_pair('a'+i,cnt[i]));
		if (mem.size() <= 4) {
			int arr[4] = {0,1,2,3};
			bool ok = false;
			do {
				bool flag = true;
				for (int i=0;i<mem.size()-1 && flag;i++)
					if (abs(mem[arr[i]].first - mem[arr[i+1]].first) == 1) flag = false;
				if (flag) {
					ok = true;
					for (int i=0;i<mem.size();i++) for (int j=0;j<mem[arr[i]].second;j++) putchar(mem[arr[i]].first);
					break;
				}
			}
			while (next_permutation(arr,arr+mem.size()));
			if (!ok) printf("No answer");
		}
		else {
			for (int i=0;i<mem.size();i+=2) {
				for (int j=0;j<mem[i].second;j++) putchar(mem[i].first);
			}
			for (int i=1;i<mem.size();i+=2) {
				for (int j=0;j<mem[i].second;j++) putchar(mem[i].first);
			}
		}
		printf("\n");
	}
	return 0;
}
