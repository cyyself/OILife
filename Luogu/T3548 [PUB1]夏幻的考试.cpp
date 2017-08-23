#include <cstdio>
#include <cstring>
int toint(char *s) {
	int t = 0;
	int a = 1;
	for (int i=strlen(s)-1;i>=0;i--) {
		if (s[i] == '1') {
			t += a;
		}
		a *= 2;
	}
	return t;
}
bool judge(char *stuans,char stdans,int num) {
	bool ret = false;
	int pos = stdans - 'A';
	for (int i=0;i<strlen(stuans);i++) 
		if (stuans[i] == '1') 
			if (i == pos) ret = true;
			else return false;
	return ret;
}
int main() {
	int T,n;
	char ans[55];
	scanf("%d%d",&T,&n);
	scanf("%s",ans);
	char buf[20];
	char type[5];
	while(T--) {
		scanf("%s",buf);
		int id = toint(buf);
		scanf("%s",type);
		int correct = 0;
		for (int i=0;i<n;i++) {
			char stuans[10];
			scanf("%s",stuans);
			correct += judge(stuans,ans[i],i);
		}
		if (id > 10000 || id < 1) {
			printf("Wrong ID\n\n");
			continue;
		}
		printf("ID: %d\n",id);
		if (strlen(type) == 2 && (type[0] == '0' || type[0] == '1') && (type[1] == '0' || type[1] == '1') && type[0] != type[1] && type[1] == buf[strlen(buf)-1])
			printf("Type Correct\n");
		else printf("Type Incorrect\n");
		printf("%0.1lf\n\n",100.0*correct/n);
	}
	return 0;
}