#include <cstdio>
struct pl{
	int w,b;
}s[15];
int n;
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long t = exgcd(b,a%b,y,x);
		y -= x * (a/b);
		return t;
	}
}
/*
int exgcd(int a,long long b,long long &x,long long &y)
{
    if(b==0) 
    {
    	x=1;y=0;
    	return a;
    }
    int d;
    d=exgcd(b,a%b,y,x);
    int tmp=a/b*x;
    x=y;y-=tmp;
}
*/
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&s[i].w,&s[i].b);
    }
    long long lcm=1;
    for(int i=1;i<=n;i++) lcm=lcm*s[i].w;
    long long ret=0,x,y;
    for(int i=1;i<=n;i++) {
    	x = 0;
    	y = 0;
    	long long t=lcm/s[i].w;
        exgcd(t,s[i].w,x,y);
        ret=((ret+t*x*s[i].b)+lcm)%lcm;
    }
    printf("%lld\n",(ret+lcm)%lcm);
	return 0;
}