#include <iostream>
#include <algorithm>
using namespace std;
struct task{
	int deadline;
	int cost;
};
bool comp(task a,task b) {
	if (a.cost > b.cost) return true;
	if (a.cost == b.cost && a.deadline < b.deadline) return true;
	return false;
}
int main() {
	int m,n;
	cin >> m >> n;
	task t[505];
	for (int i=1;i<=n;i++) cin >> t[i].deadline;
	for (int i=1;i<=n;i++) {
		cin >> t[i].cost;
		m -= t[i].cost;//先扣掉这份钱
	}
	sort(t+1,t+n+1,comp);
	//for (int i=1;i<=n;i++) cout << t[i].deadline << "	" << t[i].cost << endl;
	int tot = 0;
	int time[505]={0};//每个时间点做游戏免去扣的钱
	for (int i=1;i<=n;i++) {
		for (int j=t[i].deadline;j>=1;j--) {
			if (time[j] == 0) {
				time[j] = t[i].cost;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++) m += time[i];//加回来
	cout << m << endl;
	return 0;
}