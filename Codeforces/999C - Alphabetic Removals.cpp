#include <bits/stdc++.h>
using namespace std;
int n,k;
char s[400005];
char r[400005];
int cnt[26];
int used[26];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=0;i<n;i++) cnt[s[i]-'a'] ++;
	int pos = 0;
	for (int i=0;i<k;i++) {
		while (cnt[pos] == 0) pos ++;
		cnt[pos] --;
	}
	stack <char> st;
	for (int i=n-1;i>=0;i--) {
		if (used[s[i]-'a'] < cnt[s[i]-'a']) {
			st.push(s[i]);
			used[s[i]-'a']++;
		}
	}
	while (!st.empty()) {
		printf("%c",st.top());
		st.pop();
	}
	return 0;
}