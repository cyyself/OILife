#include <bits/stdc++.h>
using namespace std;
map <int,int> mem;
long long f[20][50][2521];
int num[20];
int gcd(int a,int b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
long long dfs(int dep,int curlcm,int cur,bool uplimited) {
	if (dep == -1) return (cur % curlcm == 0);
	else {
		int up = 9;
		if (!uplimited && f[dep][ mem[curlcm] ][cur] != -1) return f[dep][ mem[curlcm] ][cur];
		if (uplimited) up = num[dep];
		long long ans = 0;
		for (int i=0;i<=up;i++) {
			int nextlcm;
			if (i != 0) {
				int g = gcd(curlcm,i);
				nextlcm = curlcm * i / g;
			}
			else nextlcm = curlcm;
			ans += dfs(dep-1,nextlcm,(10*cur+i)%2520,uplimited && i == up);
		}
		if (!uplimited) f[dep][ mem[curlcm] ][cur] = ans;
		return ans;
	}
}
long long solve(long long x) {
	int len = 0;
	while (x) {
		num[len++] = x % 10;
		x /= 10;
	}
	return dfs(len-1,1,0,true);
}
void init() {
	mem[1]=1;
	mem[2]=2;
	mem[3]=3;
	mem[4]=4;
	mem[5]=5;
	mem[6]=6;
	mem[7]=7;
	mem[8]=8;
	mem[9]=9;
	mem[10]=10;
	mem[12]=11;
	mem[14]=12;
	mem[15]=13;
	mem[18]=14;
	mem[20]=15;
	mem[21]=16;
	mem[24]=17;
	mem[28]=18;
	mem[30]=19;
	mem[35]=20;
	mem[36]=21;
	mem[40]=22;
	mem[42]=23;
	mem[45]=24;
	mem[56]=25;
	mem[60]=26;
	mem[63]=27;
	mem[70]=28;
	mem[72]=29;
	mem[84]=30;
	mem[90]=31;
	mem[105]=32;
	mem[120]=33;
	mem[126]=34;
	mem[140]=35;
	mem[168]=36;
	mem[180]=37;
	mem[210]=38;
	mem[252]=39;
	mem[280]=40;
	mem[315]=41;
	mem[360]=42;
	mem[420]=43;
	mem[504]=44;
	mem[630]=45;
	mem[840]=46;
	mem[1260]=47;
	mem[2520]=48;
}
int main() {
	memset(f,-1,sizeof(f));
	init();
	int T;
	scanf("%d",&T);
	while (T --) {
		long long l,r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}
	return 0;
}
