#include <bits/stdc++.h>
using namespace std;
int w[26];
int sum[500005];
char s[500005];
int r_odd[500005];
int r_even[500005];
//r[i]代表以i为中心的回文串长度
char m[1000005];
int p[1000005];
bool judge(int l,int r) {
	int len = r - l + 1;
	if (len & 1) {
		//奇数
		int mid = r - len / 2;
		return (r_odd[mid] >= len);
	}
	else {
		//偶数
		int mid = r - len / 2 + 1;
		return (r_even[mid] >= len);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		for (int i=0;i<26;i++) scanf("%d",&w[i]);
		scanf("%s",s);
		int len = strlen(s);
		sum[0] = w[s[0]-'a'];
		for (int i=1;i<len;i++) sum[i] = w[s[i]-'a'] + sum[i-1];
		m[0] = '$';
		m[1] = '#';
		int j = 2;
		for (int i=0;i<len;i++) {
			m[j++] = s[i];
			m[j++] = '#';
		}
		int mx = 0;
		int id = 0;
		for (int i=1;i<j;i++) {
			if (i < mx) p[i] = min(p[2*id-i],mx-i);
			else p[i] = 1;
			while (m[i+p[i]] == m[i-p[i]]) p[i] ++;
			if (i + p[i] > mx) {
				id = i;
				mx = i + p[i];
			}
			int curlen = p[i]-1;
			if (m[i] == '#') {
				//偶数
				r_even[(i-1)/2] = max(curlen,r_even[(i-1)/2]);
			}
			else {
				r_odd[(i-1)/2] = max(curlen,r_odd[(i-1)/2]);
			}	
		}
		int ans = 0;
		for (int i=0;i<len-1;i++) {
			//0..i为substr1 i+1...len-1为substr2
			int tmp = 0;
			if (judge(0,i)) tmp += sum[i];
			if (judge(i+1,len-1)) tmp += sum[len-1] - sum[i];
			ans = max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
