//NOIP2015提高组D2T1
//审题：“最短跳跃距离的最大值”即为在可以移走石头数量允许的情况中，每种距离下跳跃的最短距离，这些情况中最短距离的最大值
#include <cstdio>
using namespace std;
int L,N,M;
int stone[50005];
bool jump(int dis){//用于判断该跳跃距离是否可以控制移走的石头数量<=M
	int last = 0,cnt = 0;//cnt为移走石子的数量
	for (int i=0;i<=N;i++){//当跳跃时有一个石头小于dis时，那么就移走这个石头，在cnt中记录移走石头的数量
		if (stone[i]-last < dis) cnt ++;//移走该石头，并且last值不变，这样下次跳的时候算出的距离就跨越了两个石头
		else last = stone[i];//跳一个石头
	}
	return cnt <= M;
}
int main(){
	scanf("%d%d%d",&L,&N,&M);
	for (int i=0;i<N;i++) scanf("%d",&stone[i]);
	stone[N] = L;
	int left = 0, right = L, ans;
	while(left <= right){//二分查找，意在找出在可以移走石头数量允许的情况下，距离的最大值
		int mid = (left + right) / 2;
		if (jump(mid)){
			ans = mid;
			left = mid + 1;//这个距离合适，更大点试试看，但需要注意的是，更大之后不一定有解，因此这里需要记录下ans
		}
		else right = mid - 1;//距离太长，缩短一半
	}
	printf("%d\n",ans);
	return 0;
}