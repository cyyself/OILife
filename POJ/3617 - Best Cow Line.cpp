#include <cstdio>
char s[2005];
char res[2005];
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		res[n] = 0;
		for (int i=0;i<n;i++) {
			scanf(" %c",&s[i]);
		}
		int l = 0;
		int r = n - 1;
		while (l <= r) {
			bool left = true;
			int _l = l;
			int _r = r;
			while (_l <= _r) {
				if (s[_l] < s[_r]) break;
				if (s[_l] > s[_r]) {
					left = false;
					break;
				}
				_l ++;
				_r --;
			}

			if(left) {
				res[l+n-1-r] = s[l];
				l ++;
			}
			else {
				res[l+n-1-r] = s[r];
				r --;
			}
		}
		for (int i=0;i<n;i++) {
			if (i % 80 == 0 && i != 0) printf("\n");
			printf("%c",res[i]);
		}
		printf("\n");
	}
	return 0;
}
