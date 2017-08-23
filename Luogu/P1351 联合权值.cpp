#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct Point{
	int weight;
	int max;//最大值，在main中用memset清零 
	int smax;//次大值 
	vector <int> set;
}a[200005];
int n;
int main(){
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u].set.push_back(v);//link
		a[v].set.push_back(u);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i].weight);
	}
	int maxnum = 0;
	int ans = 0;
	for (int i=1;i<=n;i++){//最大值预处理 
		long long weightt = 0;
		for (int j=0;j<a[i].set.size();j++) {
			weightt += a[a[i].set[j]].weight;
			if (a[a[i].set[j]].weight > a[i].max){
				a[i].smax = a[i].max;
				a[i].max = a[a[i].set[j]].weight;
			}
			else{
				if (a[a[i].set[j]].weight > a[i].smax) a[i].smax = a[a[i].set[j]].weight;
			}
		}
		weightt = weightt * weightt;
		for (int j=0;j<a[i].set.size();j++) weightt -= a[a[i].set[j]].weight * a[a[i].set[j]].weight;
        ans = (ans + weightt) % 10007;
		int t = a[i].max * a[i].smax;
		if (t > maxnum) maxnum = t;
	}
	
		

	/*
	for (int i=1;i<=n;i++){
		for (int j=0;j<a[i].set.size();j++){
			int add = 0;
			for (int k=0;k<a[i].set.size();k++){
				if (j != k) add = (add + a[a[i].set[k]].weight) % 10007;
			}
			ans = (ans + a[a[i].set[j]].weight * add ) % 10007;
		}
	}
	*/
	printf("%d %d",maxnum,ans);
	return 0;
}