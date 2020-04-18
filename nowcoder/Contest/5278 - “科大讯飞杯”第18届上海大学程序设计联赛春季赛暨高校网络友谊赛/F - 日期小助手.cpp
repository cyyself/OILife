#include <bits/stdc++.h>
using namespace std;
const int days[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
bool is_run(int y) {
	if (y % 4 == 0) {
		if (y % 100 == 0) {
			if (y % 400 == 0) return true;
			else return false;
		}
		else return true;
	}
	else return false;
}
vector <pair<int,pair<int,int> > > date;
int main() {
	int curw = 6;
	for (int y=2000;y<=2101;y++) {
		for (int m=1;m<=12;m++) {
			if (m == 2 && !is_run(y)) {
				for (int d=1;d<=28;d++) {
					curw = (curw+1) % 7;
				}
			}
			else {
				int cnt = 0;
				for (int d=1;d<=days[m];d++) {
					if (curw == 0) {
						cnt ++;
						if (m == 5 && cnt == 2) {
							date.push_back(make_pair(y,make_pair(m,d)));
						}
						else if (m == 6 && cnt == 3) {
							date.push_back(make_pair(y,make_pair(m,d)));
						}
					}
					curw = (curw+1) % 7;
				}
			}
		}
	}
	int T;
	scanf("%d",&T);
	while (T --) {
		int y,m,d;
		scanf("%d%d%d",&y,&m,&d);
		pair <int,pair<int,int> > x = {y,{m,d}};
		auto it = upper_bound(date.begin(),date.end(),x);
		if (it->second.first == 5) printf("Mother's Day: May ");
		else printf("Father's Day: June ");
		if (it->second.second == 1 || it->second.second == 21) printf("%dst, ",it->second.second);
		else if (it->second.second == 2 || it->second.second == 22) printf("%dnd, ",it->second.second);
		else if (it->second.second == 3 || it->second.second == 23) printf("%drd, ",it->second.second);
		else printf("%dth, ",it->second.second);
		printf("%d\n",it->first);
	}
	return 0;
}
