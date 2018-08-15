#include <bits/stdc++.h>
using namespace std;
int strmin(char *s) {
	int i=0,j=1,k=0;
	int len = strlen(s);
	while (i < len && j < len && k < len) {
		int d = s[(i+k)%len] - s[(j+k)%len];
		if (d == 0) k ++;
		else {
			if (d > 0) i = i + k + 1;
			else j = j + k + 1;
			if (i == j) j ++;
			k = 0;
		}
	}
	return min(i,j);
}
string tostr(char *s,int start) {
	int len = strlen(s);
	string ret = "";
	int pos = start;
	for (int i=0;i<len;i++) {
		ret += s[pos%len];
		pos ++;
	}
	return ret;
}
char tmp[105];
map <string,bool> exist;
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		exist.clear();
		int cnt = 0;
		while (n--) {
			scanf("%s",tmp);
			string curmin = tostr(tmp,strmin(tmp));
			if (!exist[curmin]) {
				exist[curmin] = true;
				cnt ++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
