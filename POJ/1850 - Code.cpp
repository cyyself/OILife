/*
#include <bits/stdc++.h>
typedef unsigned long long llu;
llu getdelta(int pos,int num) {
	if (25 - num < pos) return 0;
	if (pos == 0) return 1;
	//pos是第几位，比如abcde,pos=4,num=0
	llu ans = 1;
	for (int i=26-pos-num;i<=25-num;i++) ans *= i;
	for (int i=2;i<=pos;i++) ans /= i;
	return ans;
}
int main() {
	llu cur = 0;
	for (int i=0;i<=9;i++) {
		for (int j=0;j<=25-i;j++) cur += getdelta(i,j);
		printf("%llu\n",cur+1);
	}
	return 0;
}
*/
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
typedef unsigned long long llu;
llu getdelta(int pos,int num) {
	if (25 - num < pos) return 0;
	if (pos == 0) return 1;
	//pos是第几位，比如abcde,pos=4,num=0
	llu ans = 1;
	for (int i=26-pos-num;i<=25-num;i++) ans *= i;
	for (int i=2;i<=pos;i++) ans /= i;
	return ans;
}
int ind[11] = {//index
	1,
	27,
	352,
	2952,
	17902,
	83682,
	313912,
	971712,
	2533987,
	5658537,
	10970272
};
int main() {
	char s[15];
	scanf("%s",s);
	int len = strlen(s);
	int cur = ind[len-1];
	char curs[15] = {0};
	for (int i=1;i<len;i++) if (s[i] < s[i-1]) {
		printf("0\n");
		return 0;
	}
	for (int i=0;i<len;i++) curs[i] = 'a' + i;
	for (int i=0;i<len;i++) {
		while (curs[i] < s[i]) {
			cur += getdelta(len-1-i,curs[i]-'a');
			for (int j=i;j<len;j++) curs[j] ++;
		}
	}
	printf("%d\n",cur);
	return 0;
}