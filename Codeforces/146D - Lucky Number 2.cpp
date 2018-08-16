#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (abs(c-d) > 1 || a+b <= c+d || a<c || a<d || b<c || b<d ) printf("-1");
	else {
		if (c > d) {
			//47 > 74
			for (int i=0;i<a-d;i++) printf("4");
			for (int i=0;i<d;i++) printf("74");
			for (int i=0;i<b-d;i++) printf("7");
		}
		else if (c == d) {
			if (a > c) {
				for (int i=0;i<a-c-1;i++) printf("4");
				for (int i=0;i<c;i++) printf("47");
				for (int i=0;i<b-c;i++) printf("7");
				printf("4");
			}
			else {
				printf("7");
				for (int i=0;i<c;i++) printf("47");
				for (int i=0;i<b-1-c;i++) printf("7");
			}
		}
		else {
			//74 > 47
			printf("7");
			for (int i=0;i<a-c-1;i++) printf("4");
			for (int i=0;i<c;i++) printf("47");
			for (int i=0;i<b-c-1;i++) printf("7");
			printf("4");
		}
	}
	printf("\n");
	return 0;
}
