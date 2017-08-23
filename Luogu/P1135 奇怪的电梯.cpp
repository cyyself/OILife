#include <iostream>
#include <queue>
using namespace std;
struct Elevator{
	int step;
	int floor;//楼层
	Elevator(int _step,int _floor):step(_step),floor(_floor){}
};

int main() {
	int N,A,B;
	cin >> N >> A >> B;
	int K[205];
	for (int i=1;i<=N;i++) cin >> K[i];
	queue <Elevator> q;
	bool vis[205] = {0};
	q.push(Elevator(0,A));
	vis[A] = true;
	int ans = -1;
	while(!q.empty()){
		Elevator curr = q.front();
		q.pop();
		if (curr.floor == B) {
			ans = curr.step;
			break;
		}
		if (curr.floor + K[curr.floor] <= N) if (!vis[curr.floor+K[curr.floor]]) {
			q.push(Elevator(curr.step+1,curr.floor + K[curr.floor]));
			vis[curr.floor+K[curr.floor]] = true;
		}
		if (curr.floor - K[curr.floor] >= 1) if (!vis[curr.floor-K[curr.floor]]) {
			q.push(Elevator(curr.step+1,curr.floor - K[curr.floor]));
			vis[curr.floor-K[curr.floor]] = true;
		}
	}
	cout << ans << endl;
	return 0;
}