#include <bits/stdc++.h>
using namespace std;
int n;
char s[105];
void reverse(int l,int r) {
	while (l < r) {
		swap(s[l],s[r]);
		l ++;
		r --;
	}
}
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	stack <int> st;
	for (int i=n;i>=1;i--) {
		if (n % i == 0) st.push(i);
	}
	while (!st.empty()) {
		reverse(0,st.top()-1);
		st.pop();
	}
	printf("%s\n",s);
	return 0;
}