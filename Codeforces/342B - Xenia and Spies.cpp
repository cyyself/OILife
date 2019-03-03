#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int t,l,r;
	void read() {
		scanf("%d%d%d",&t,&l,&r);
	}
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.t < b.t;
	}
}w[100000];
int main() {
	int n,m,s,f;
	scanf("%d%d%d%d",&n,&m,&s,&f);
	for (int i=0;i<m;i++) w[i].read();
	sort(w,w+m);
	int t = 1;
	int cur = s;
	int d = f>s?1:-1;
	int ptr = 0;
	while (cur != f) {
		if (ptr < m && w[ptr].t == t && ((cur + d >= w[ptr].l && cur+ d <= w[ptr].r) || (cur >= w[ptr].l && cur <= w[ptr].r)) ) {
			printf("X");
		}
		else {
			if (d == 1) printf("R");
			else printf("L");
			cur += d;
		}
		if (ptr < m && w[ptr].t == t) ptr++;
		t ++;
	}
	printf("\n");
	return 0;
}
