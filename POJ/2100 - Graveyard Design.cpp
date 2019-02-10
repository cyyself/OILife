#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int,int> > ans;
bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
	return a.second - a.first > b.second - b.first;
}
int main() {
	long long n;
	while (cin >> n) {
		ans.clear();
		long long head = 1;//要记得开ll，由于队列都是按顺序的，就不需要开一个真实的队列了
		long long sum = 1;
		if (n == 1) ans.push_back(make_pair(1,1));
		for (long long i=2;i*i<=n;i++) {
			sum += i * i;
			while (sum > n && head < i) {
				sum -= head * head;
				head ++;
			}
			if (sum == n) {
				ans.push_back(make_pair(head,i));
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		int l = ans.size();
		printf("%d\n",l);
		for (int i=0;i<l;i++) {
			printf("%d",ans[i].second-ans[i].first+1);
			for (int j=ans[i].first;j<=ans[i].second;j++) {
				printf(" %d",j);
			}
			printf("\n");
		}
	}
	return 0;
}
