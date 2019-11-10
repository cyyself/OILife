#include <bits/stdc++.h>
using namespace std;
char s[200005];
int slen;
int b[200005];
int a[200005];
int n,m;
bool cal_b(int a1) {
	int ptr = 0;
	for (int i=0;i<m;i++) {
		if (ptr >= slen) return false;
		if ((s[ptr]-'0') % a1 == 0) {
			b[i] = (s[ptr]-'0') / a1;
			ptr ++;
		}
		else if (ptr + 1 < slen && ((s[ptr]-'0') * 10 + (s[ptr+1]-'0')) % a1 == 0) {
			b[i] = ((s[ptr]-'0') * 10 + (s[ptr+1]-'0')) / a1;
			ptr += 2;
		}
		else return false;
		if (b[i] >= 10) return false;
	}
	return true;
}
bool cal_a() {
	int ptr = 0;
	for (int i=0;i<n;i++) {
		a[i] = -1;
		for (int j=0;j<m;j++) {
			if (ptr >= slen) return false;
			if (
				(b[j] == 0 && (s[ptr]-'0') == 0) || 
				(b[j] != 0 && (s[ptr]-'0') % b[j] == 0)
			) {
				if (b[j] != 0) {
					int nai = (s[ptr]-'0') / b[j];
					if (nai >= 10) return false;
					if (a[i] != -1 && nai != a[i]) return false;
					a[i] = nai;
				}
				ptr ++;
			}
			else if (ptr + 1 < slen && b[j] != 0 && ((s[ptr]-'0') * 10 + (s[ptr+1]-'0')) % b[j] == 0 ) {
				int nai = ((s[ptr]-'0') * 10 + (s[ptr+1]-'0')) / b[j];
				if (nai >= 10) return false;
				if (a[i] != -1 && nai != a[i]) return false;
				a[i] = nai;
				ptr += 2;
			}
			else return false;
		}
	}
	return ptr == slen;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&m);
		scanf("%s",s);
		slen = strlen(s);
		bool allzero = true;
		for (int i=0;i<slen;i++) if (s[i] != '0') allzero = false;
		if (allzero) {
			if (min(n,m) == 1 && max(n,m) == slen) {
				if (slen == 1) printf("0 0\n");
				else {
					if (n == 1) {
						printf("0 1");
						for (int i=1;i<slen;i++) printf("0");
						printf("\n");
					}
					else {
						printf("1");
						for (int i=1;i<slen;i++) printf("0");
						printf(" 0\n");
					}
				}
			}
			else printf("Impossible\n");
			continue;
		}
		bool ans = false;
		for (int a1=1;a1<=9;a1++) {
			if (!cal_b(a1)) continue;
			if (cal_a()) {
				ans = true;
				for (int i=0;i<n;i++) printf("%d",a[i]);
				printf(" ");
				for (int i=0;i<m;i++) printf("%d",b[i]);
				printf("\n");
				break;
			}
			/*
			printf("debug begin: a1=%d\n",a1);
			for (int i=0;i<m;i++) printf("%d\t",b[i]);
			printf("\ndebug end\n");
			*/
		}
		if (!ans) printf("Impossible\n");
	}
	return 0;
}
