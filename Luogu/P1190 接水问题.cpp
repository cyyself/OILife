#include <cstdio>
#include <algorithm>
using namespace std;
#define QLEN 10005
int n,m;
int qtime[QLEN];
int addtoqueue(int w){//返回需要等待的时间
	int mi = qtime[0];//min
	int p = 0;
	for (int i=1;i<m;i++){
		if (qtime[i] < mi) {
			mi = qtime[i];
			p = i;
		}
	}
	for (int i=0;i<m;i++) qtime[i] -= mi;
	qtime[p] = w;
	return mi;
}
int main(){
	long long time = 0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int w;
		scanf("%d",&w);
		time += addtoqueue(w);
	}
	int qmax = 0;
	for (int i=0;i<n;i++) qmax = max(qmax,qtime[i]);
	time += qmax;
	printf("%lld",time);
	return 0;
}