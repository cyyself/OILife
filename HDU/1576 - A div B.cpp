#include <cstdio>
long long gcd(int a,int b,int &x,int &y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	else{
		int t = gcd(b,a%b,y,x);
		y-=x*(a/b);
		return t;
	}
}
int main(){
	long long x=0,y=0;
	int T;
	scanf("%d",&T);
	while(T--){
		int n,B;
		scanf("%d%d",&n,&B);
		//求B关于m的乘法逆元
		int x,k;
		int g = gcd(B,9973,x,k);
		x=(x%9973+9973)%9973;
		printf("%d\n",(x*n)%9973);
	}
	return 0;
}