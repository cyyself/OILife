#include <bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005],c[1000005];
int lena,lenb,lenc;
int sufa,sufb,sufc;
int tmp[1000005];
int geta(int pos) {
	if (pos >= lena || pos < 0) return 0;
	return a[pos] - '0';
}
int getb(int pos) {
	if (pos >= lenb || pos < 0) return 0;
	return b[pos] - '0';
}
int getc(int pos) {
	if (pos >= lenc || pos < 0) return 0;
	return c[pos] - '0';
}
bool check1() {//a和c的高位对齐
	int totlen = max(lena,lenc);
	int x = totlen - lena;
	int z = totlen - lenc;
	int dec = 0;
	for (int i=totlen-1;i>=0;i--) {
		if (getc(i) - geta(i) - dec < 0) {
			tmp[i] = getc(i) - geta(i) - dec + 10;
			dec = 1;
		}
		else {
			tmp[i] = getc(i) - geta(i) - dec;
			dec = 0;
		}
	}
	if (dec == 1) return false;
	int st = 0;
	while (tmp[st] == 0 && st < totlen) st++;
	if (totlen - st >= lenb-sufb) {
		for (int i=st;i<st+lenb-sufb;i++) {
			if (tmp[i] != getb(i-st)) return false;
		}
		for (int i=st+lenb-sufb;i<totlen;i++) {
			if (tmp[i] != 0) return false;
		}
		int y = totlen - (st + lenb);
		if (y < 0) {
			x -= y;
			z -= y;
			y = 0;
		}
		if (x > 1000000 || y > 1000000 || z > 1000000) return false;
		printf("%d %d %d\n",x,y,z);
		return true;
	}
	else return false;
}
bool check2() {//b和c的高位对齐
	int totlen = max(lenb,lenc);
	int y = totlen - lenb;
	int z = totlen - lenc;
	int dec = 0;
	for (int i=totlen-1;i>=0;i--) {
		if (getc(i) - getb(i) - dec < 0) {
			tmp[i] = getc(i) - getb(i) - dec + 10;
			dec = 1;
		}
		else {
			tmp[i] = getc(i) - getb(i) - dec;
			dec = 0;
		}
	}
	if (dec == 1) return false;
	int st = 0;
	while (tmp[st] == 0 && st < totlen) st++;
	if (totlen - st >= lena-sufa) {
		for (int i=st;i<st+lena-sufa;i++) {
			if (tmp[i] != geta(i-st)) return false;
		}
		for (int i=st+lena-sufa;i<totlen;i++) {
			if (tmp[i] != 0) return false;
		}
		int x = totlen - (st + lena);
		if (x < 0) {
			y -= x;
			z -= x;
			x = 0;
		}
		if (x > 1000000 || y > 1000000 || z > 1000000) return false;
		printf("%d %d %d\n",x,y,z);
		return true;
	}
	else return false;
}
bool check3() {//a和c的高位-1对齐
	int totlen = max(lena+1,lenc);
	int x = totlen - lena - 1;
	int z = totlen - lenc;
	int dec = 0;
	for (int i=totlen-1;i>=0;i--) {
		if (getc(i) - geta(i-1) - dec < 0) {
			tmp[i] = getc(i) - geta(i-1) - dec + 10;
			dec = 1;
		}
		else {
			tmp[i] = getc(i) - geta(i-1) - dec;
			dec = 0;
		}
	}
	if (dec == 1) return false;
	int st = 0;
	while (tmp[st] == 0 && st < totlen) st++;
	if (totlen - st >= lenb-sufb) {
		for (int i=st;i<st+lenb-sufb;i++) {
			if (tmp[i] != getb(i-st)) return false;
		}
		for (int i=st+lenb-sufb;i<totlen;i++) {
			if (tmp[i] != 0) return false;
		}
		int y = totlen - (st + lenb);
		if (y < 0) {
			x -= y;
			z -= y;
			y = 0;
		}
		if (x > 1000000 || y > 1000000 || z > 1000000) return false;
		printf("%d %d %d\n",x,y,z);
		return true;
	}
	else return false;
}
bool check4() {//b和c的高位-1对齐
	int totlen = max(lenb+1,lenc);
	int y = totlen - lenb - 1;
	int z = totlen - lenc;
	int dec = 0;
	for (int i=totlen-1;i>=0;i--) {
		if (getc(i) - getb(i-1) - dec < 0) {
			tmp[i] = getc(i) - getb(i-1) - dec + 10;
			dec = 1;
		}
		else {
			tmp[i] = getc(i) - getb(i-1) - dec;
			dec = 0;
		}
	}
	if (dec == 1) return false;
	int st = 0;
	while (tmp[st] == 0 && st < totlen) st++;
	if (totlen - st >= lena-sufa) {
		for (int i=st;i<st+lena-sufa;i++) {
			if (tmp[i] != geta(i-st)) return false;
		}
		for (int i=st+lena-sufa;i<totlen;i++) {
			if (tmp[i] != 0) return false;
		}
		int x = totlen - (st + lena);
		if (x < 0) {
			y -= x;
			z -= x;
			x = 0;
		}
		if (x > 1000000 || y > 1000000 || z > 1000000) return false;
		printf("%d %d %d\n",x,y,z);
		return true;
	}
	else return false;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s%s%s",a,b,c);
		lena = strlen(a);
		lenb = strlen(b);
		lenc = strlen(c);
		sufa = sufb = sufc = 0;
		while (a[lena - sufa - 1] == '0') sufa ++;
		while (b[lenb - sufb - 1] == '0') sufb ++;
		while (c[lenc - sufc - 1] == '0') sufc ++;
		if (!check1() && !check2() && !check3() && !check4()) printf("-1\n");
	}
	return 0;
}
