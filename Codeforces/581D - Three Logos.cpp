#include <bits/stdc++.h>
using namespace std;
struct logo {
	int x,y;
	int index;
	friend bool operator < (const logo &a,const logo &b) {
		if (a.x < b.x) return true;
		if (a.x == b.x && a.y < b.y) return true;
		return false;
	}
}l[3];
int main() {
	for (int i=0;i<3;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (x < y) swap(x,y);
		l[i].x = x;
		l[i].y = y;
		l[i].index = i;
	}
	sort(l,l+3);
	int per[3] = {0,1,2};
	bool ok = false;
	do {
		for (int p=0;p<=7 && !ok;p++) {
			for (int i=0;i<3;i++) if (p & (1 << i)) swap(l[per[i]].x,l[per[i]].y);
			if (l[per[0]].y + l[per[1]].y == l[per[2]].x && l[per[0]].x == l[per[1]].x && l[per[2]].x == l[per[0]].x + l[per[2]].y) {
				ok = true;
				printf("%d\n",l[per[2]].x);
				for (int i=0;i<l[per[2]].y;i++) {
					for (int j=0;j<l[per[2]].x;j++) printf("%c",'A'+l[per[2]].index);
					printf("\n");
				}
				for (int i=0;i<l[per[0]].x;i++) {
					for (int j=0;j<l[per[0]].y;j++) printf("%c",'A'+l[per[0]].index);
					for (int j=0;j<l[per[1]].y;j++) printf("%c",'A'+l[per[1]].index);
					printf("\n");
				}
			}
			for (int i=0;i<3;i++) if (p & (1 << i)) swap(l[per[i]].x,l[per[i]].y);
		}

	} while (next_permutation(per,per+3) && !ok);
	if (!ok) {
		if (l[0].x == l[1].x && l[1].x == l[2].x) {
			if (l[0].y + l[1].y + l[2].y == l[0].x) {
				ok = true;
				printf("%d\n",l[0].x);
				for (int i=0;i<l[0].y;i++) {
					for (int j=0;j<l[0].x;j++) printf("%c",'A'+l[0].index);
					printf("\n");
				}
				for (int i=0;i<l[1].y;i++) {
					for (int j=0;j<l[1].x;j++) printf("%c",'A'+l[1].index);
					printf("\n");
				}
				for (int i=0;i<l[2].y;i++) {
					for (int j=0;j<l[2].x;j++) printf("%c",'A'+l[2].index);
					printf("\n");
				}
			}
		}
	}
	if (!ok) printf("-1\n");
	return 0;
}
