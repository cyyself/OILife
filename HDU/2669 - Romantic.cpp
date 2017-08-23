#include <cstdio>
using namespace std;
long long gcd(long long a,long long b,long long &x,long long &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	else{
		long long t = gcd(b,a%b,y,x);
		y-=x*(a/b);
		return t;
	}
}
int main(){
	long long a,b;
	while(scanf("%lld%lld",&a,&b) == 2){
		long long x=0,y=0;
		long long g = gcd(a,b,x,y);
		if (g == 1) {
			if (x < 0) {
				x += b;
				y = (1-a*x)/b;
			}
			printf("%lld %lld\n",x,y);
		}
		else printf("sorry\n");
	}
	return 0;
}