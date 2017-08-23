#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct edge{
	int to, weight;
};
vector <edge> sheet[2501];
void addEdge(int from,int to,int weight){
	edge e;
	e.to = to;
	e.weight = weight;
	sheet[from].push_back(e);
	e.to = from;
	sheet[to].push_back(e);
}
int SPFA(int source,int end){
	int distance[2501];
	bool inqueue[2501];
	queue <int> q;
	memset(distance,0x3F,sizeof(distance));
	memset(inqueue,false,sizeof(inqueue));
	distance[source] = 0;
	q.push(source);
	inqueue[source]  = true;
	while(!q.empty()){
		int num = q.front();
		q.pop();
		inqueue[num] = false;
		for (int i=0;i < sheet[num].size();i++){
			if (distance[num] + sheet[num][i].weight < distance[sheet[num][i].to]){
				distance[sheet[num][i].to] = distance[num] + sheet[num][i].weight;
				if (!inqueue[sheet[num][i].to]){
					q.push(sheet[num][i].to);
					inqueue[sheet[num][i].to] = true;
				}
			}
		}
	}
	return distance[end];
}
int main(){
	int T,C,Ts,Te;
	cin >> T >> C >> Ts >> Te;
	for (int i=0;i<C;i++){
		int from,to,weight;
		cin >> from >> to >> weight;
		addEdge(from,to,weight);
	}
	cout << SPFA(Ts,Te) << endl;
	return 0;
}