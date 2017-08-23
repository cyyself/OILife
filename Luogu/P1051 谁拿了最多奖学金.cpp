#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
struct stu {
	string name;
	int score;
}s[105];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int q,b;
		char g,x;
		int l;
		cin >> s[i].name;
		cin >> q >> b >> g >> x >> l;
		if (q > 80 && l >= 1) s[i].score += 8000;
		if (q > 85 && b > 80) s[i].score += 4000;
		if (q > 90) s[i].score += 2000;
		if (q > 85 && x == 'Y') s[i].score += 1000;
		if (b > 80 && g == 'Y') s[i].score += 850;
	}
	int top = 0;
	int tot = s[0].score;
	for (int i=1;i<n;i++) {
		tot += s[i].score;
		if (s[i].score > s[top].score) top = i;
	}
	cout << s[top].name << endl;
	cout << s[top].score << endl;
	cout << tot << endl;
	return 0;
}