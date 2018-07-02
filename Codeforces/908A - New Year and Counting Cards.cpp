#include <bits/stdc++.h>
char a[55];
const char ins[10] = {'a','e','i','o','u','1','3','5','7','9'};
int main() {
	scanf("%s",a);
	int len = strlen(a);
	int cnt = 0;
	for (int i=0;i<len;i++) 
		for (int j=0;j<10;j++) 
			if (a[i] == ins[j]) {
				cnt ++;
				break;
			}
	printf("%d\n",cnt);
	return 0;
}