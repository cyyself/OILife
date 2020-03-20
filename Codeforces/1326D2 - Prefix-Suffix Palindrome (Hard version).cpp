#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
char a[maxn];
char b[maxn];
int  p[maxn];
int lena,lenb;
int len;
int getlen(int x) {
	int llen = x - p[x];
	int rlen = lenb - (x + p[x]);
	int s = min(llen,rlen);
	if (s > len) return -1;
	return p[x] * 2 - 1 + s * 2;
}
void output(int x) {
	int llen = x - p[x];
	int rlen = lenb - (x + p[x]);
	int s = min(llen,rlen);
	vector <char> buf;
	for (int i=2;i<=s;i+=2) buf.push_back(b[i]);
	for (auto c:buf) printf("%c",c);
	for (int i=x-p[x]+1;i<=x+p[x]-1;i++) if (b[i] != '#') printf("%c",b[i]);
	reverse(buf.begin(),buf.end());
	for (auto c:buf) printf("%c",c);
	printf("\n");
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s",a);
		lena = strlen(a);
		b[0] = '$';
		b[1] = '#';
		int j = 2;
		for (int i=0;i<lena;i++) {
			b[j++] = a[i];
			b[j++] = '#';
		}
		b[j] = '\0';
		lenb = strlen(b);
		len = 0;
		while (b[len+1] == b[lenb-len-1]) len ++;
		int id = 0;
		int mx = 0;
		int pos = 1;
		for (int i=1;i < lenb;i++) {
			if (i < mx) p[i] = min(p[2*id-i],mx - i);
			else p[i] = 1;
			while (b[i-p[i]] == b[i+p[i]]) p[i] ++;
			if (mx < i + p[i]) {
				id = i;
				mx = i + p[i];
			}
			if (getlen(i) > getlen(pos)) pos = i;
		}
		output(pos);
		for (int i=0;i<=lenb;i++) p[i] = a[i] = b[i] = 0;
		lena = 0;
		lenb = 0;
	}
	return 0;
}
