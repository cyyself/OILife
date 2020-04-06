#include <bits/stdc++.h>
using namespace std;
int b;
char getres() {
	fflush(stdout);
	char c;
	scanf(" %c",&c);
	return c;
}
struct myarr {//only work with b % 2 == 0
	bool rev;
	bool neg;
	bool ok;
	int arr[105];
	int l,r;
	int same,diff;
	void init() {
		for (int i=1;i<=b;i++) arr[i] = -1;
		rev = false;
		neg = false;
		ok = false;
		l = 1;
		r = 1;
		same = -1;
		diff = -1;
	}
	void doneg() {
		neg ^= 1;
	}
	void dorev() {
		rev ^= 1;
	}
	int get(int x) {
		return arr[rev?b+1-x:x] ^ neg;
	}
	void set(int x,bool val) {
		arr[rev?b+1-x:x] = val ^ neg;
	}
	bool ask() {
		if (ok) return false;
		if (l <= r) {
			printf("%d\n",rev?b+1-l:l);
			set(rev?b+1-l:l,getres()-'0');
			l ++;
		}
		else if (l > r) {
			printf("%d\n",rev?r:b+1-r);
			set(rev?r:b+1-r,getres()-'0');
			r ++;
		}
		if (l == r) {
			if (get(l-1) == get(b+1-(r-1))) same = l - 1;
			else diff = l - 1;
		}
		ok = (l > b / 2 && r > b / 2);
		return true;
	}
}arr;
int ask_stat() {
	int used = 0;
	if (arr.same != -1) {
		printf("%d\n",arr.same);
		if (getres() - '0' != arr.get(arr.same)) arr.doneg();
		used ++;
	}
	if (arr.diff != -1) {
		printf("%d\n",arr.diff);
		if (getres() - '0' != arr.get(arr.diff)) arr.dorev();
		used ++;
	}
	return used;
}
void work() {
	arr.init();
	for (int i=1;i<=15;i++) {
		arr.l = arr.r = min(arr.l,arr.r);
		int used = ask_stat();
		for (int j=0;j<10-used && !arr.ok;j++) arr.ask();
		if (arr.ok) {
			for (int j=1;j<=b;j++) printf("%d",arr.get(j));
			printf("\n");
			getres();
			return;
		}
	}
}
int main() {
	int T;
	scanf("%d%d",&T,&b);
	while (T --) work();
	return 0;
}
