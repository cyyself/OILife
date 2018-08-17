#include <bits/stdc++.h>
using namespace std;
stack <int> st;
char s[200005];
bool del[200005];
int match[200005];
int main() {
	memset(match,-1,sizeof(match));
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=0;i<n;i++) {
		if (s[i] == '(') st.push(i);
		else {
			match[i] = st.top();
			st.pop();
		}
	}
	int cnt = n;
	for (int i=n-1;i>=0 && cnt > k;i--) {
		if (match[i] >= 0) {
			del[i] = true;
			del[match[i]] = true;
			cnt -= 2;
		}
	}
	for (int i=0;i<n;i++) if (!del[i]) printf("%c",s[i]);
	printf("\n");
	return 0;
}
