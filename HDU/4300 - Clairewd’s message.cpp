/*
刚开始看题目实在没理解这题要问什么，于是弃疗参考了一篇题解：
https://www.cnblogs.com/liuxin13/p/4732661.html

这题题意很坑，大概讲一下
先给你一个字符映射表，告诉你什么密文对应什么明文
比如样例第二组数据qwertyuiopasdfghjklzxcvbnm
意思是，q对应a，w对应b，以此类推

然后给出一个字符串，包含了完整的密文和不完整的明文，需要你把密文翻译出来，然后把明文补充完整。

题目的关键在于如何知道密文的最小长度。

我们可以先假定前一半是密文，后一半是明文。

解释一下为什么可以这样做：
密文长度一定大于等于长度的一半（注意当长度是奇数的时候，要向上取整）
设长度为len，假定的密文长度为mid
则后缀能匹配的长度自然是小于等于mid的
那么，我们只要正确取得了后缀匹配的长度，也就能推出后面明文的长度了


然后获取KMP的next数组，看后缀的匹配长度，这样就获得了密文的长度。
*/
#include <bits/stdc++.h>
using namespace std;
char tmp[200005];
char s[200005];
map <char,char> decrypt;

int nxt[200005];
void getnext(int n) {//从tmp数组获取
	int k = -1;
	nxt[0] = -1;
	for (int i=1;i<n;i++) {
		while (k != -1 && tmp[i] != tmp[k+1]) k = nxt[k];
		if (tmp[i] == tmp[k+1]) k ++;
		nxt[i] = k;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s",tmp);
		for (int i=0;i<26;i++) decrypt[tmp[i]] = 'a' + i;
		scanf("%s",s);
		int len = strlen(s);
		//构造字符串 {
		int mid = (len+1) / 2;//假定的密文长度
		int len2 = 0;//用于构造一个计算next数组的字符串
		for (int i=0;i<mid;i++) tmp[len2++] = decrypt[s[i]];
		tmp[len2++] = '#';
		for (int i=mid;i<len;i++) {
			tmp[len2++] = s[i];
		}
		tmp[len2] = '\0';
		//构造字符串}
		getnext(len2);
		int prefixlen = len - (nxt[len2-1]+1);//总长度-明文长度，由于我习惯的next数组从0开始，所以要+1
		len2 = 0;//重复利用tmp数组
		for (int i=0;i<prefixlen;i++) tmp[len2++] = s[i];
		for (int i=0;i<prefixlen;i++) tmp[len2++] = decrypt[s[i]];
		tmp[len2] = '\0';
		printf("%s\n",tmp);
	}
	return 0;
}
