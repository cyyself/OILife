#include <bits/stdc++.h>
int f[10005];
int t[10005];
int main() {
	int one,two,five;
	while (scanf("%d%d%d",&one,&two,&five) == 3 && (one != 0 || two != 0 || five != 0)) {
		int max = one + two * 2 + five * 5;
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		//process one and two
		for (int i=0;i<=one;i++) {
			f[i] = 1;
			for (int j=i+2;j<=i+2*two;j+=2) f[j] = 1;
		}
		//process five
		memcpy(t,f,sizeof(t));
		for (int i=0;i<=one+two*2;i++) if (f[i]) for (int j=i+5;j<=i+five*5;j++) t[j] += f[i];
		memcpy(f,t,sizeof(f));
		//check
		bool flag = true;
		for (int i=1;i<=max;i++) if (!f[i]) {
			printf("%d\n",i);
			flag = false;
			break;
		}
		if (flag) printf("%d\n",max+1);
	}
	return 0;
}