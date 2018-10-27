#include <bits/stdc++.h>
using namespace std;
char s[200005];
int n;
inline int lowbit(int x) {
	return x & (-x);
}
struct Tr {
	int a[200005];
	int sum(int _pos) {
		int ret = 0;
		for (int i=_pos;i >= 1;i -= lowbit(i)) ret += a[i];
		return ret;
	}
	int query(int _l,int _r) {
		return sum(_r) - sum(_l-1);
	}
	void insert(int _pos,int _x) {
		for (int i=_pos;i<=n;i+=lowbit(i)) a[i] += _x;
	}
}xt,yt;//X tree,Y tree
int tx,ty;//Terminal X, Terminal Y 
int cx=0,cy=0;
bool check(int len) {
	for (int s=1;s+len-1 <= n;s++) {
		int t = s + len - 1;
		int x = cx - xt.query(s,t);
		int y = cy - yt.query(s,t);
		int step = abs(x - tx) + abs(y - ty);
		if (step == len || (step < len && (len-step) % 2 == 0)) return true;
	}
	return false;
}
int main() {
	cin >> n;
	cin >> &s[1];
	cin >> tx >> ty;
	for (int i=1;i<=n;i++) {
		switch (s[i]) {
			case 'L':
				xt.insert(i,-1);
				cx --;
				break;
			case 'R':
				xt.insert(i,1);
				cx ++;
				break;
			case 'U':
				yt.insert(i,1);
				cy ++; 
				break;
			case 'D':
				yt.insert(i,-1);
				cy --;
				break;
		}
	}
	if (!check(n)) printf("-1\n");
	else {
		int l = 0;
		int r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n",l);
	}
	return 0;
}
