#include <bits/stdc++.h>
using namespace std;
char s[1005];
queue <int> l;
stack <int> r;
vector <int> ans_l,ans_r;
int main() {
	scanf("%s",s+1);
	int n = strlen(s+1);
	for (int i=1;i<=n;i++) {
		if (s[i] == '(') l.push(i);
		else r.push(i);
	}
	while (!l.empty() && !r.empty() && l.front() < r.top()) {
		ans_l.push_back(l.front());
		l.pop();
		ans_r.push_back(r.top());
		r.pop();
	}
	reverse(ans_r.begin(),ans_r.end());
	if (ans_l.size()) {
		printf("1\n%d\n",(int)ans_l.size()*2);
		for (int i=0;i<ans_l.size();i++) printf("%d ",ans_l[i]);
		for (int i=0;i<ans_r.size();i++) printf("%d%c",ans_r[i],(i==ans_r.size()-1)?'\n':' ');
	}
	else {
		printf("0\n");
	}
	return 0;
}
