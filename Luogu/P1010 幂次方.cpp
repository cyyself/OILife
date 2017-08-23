#include <cstdio>
const char table[16][32] = {
	"0",
	"2(0)",
	"2",
	"2+2(0)",
	"2(2)",
	"2(2)+2(0)",
	"2(2)+2",
	"2(2)+2+2(0)",
	"2(2+2(0))",
	"2(2+2(0))+2(0)",
	"2(2+2(0))+2",
	"2(2+2(0))+2+2(0)",
	"2(2+2(0))+2(2)",
	"2(2+2(0))+2(2)+2(0)",
	"2(2+2(0))+2(2)+2",
	"2(2+2(0))+2(2)+2+2(0)",
};
int main() {
	int n;
	scanf("%d",&n);
	bool binary[15];
	for (int i=16384,j=14;i>=1;i=i>>1,j--) {
		if (n / i == 1) {
			binary[j] = true;
			n -= 1<<j;
		}
		else binary[j] = false;
	}
	//for (int i=14;i>=0;i--) printf("%d",binary[i]);
	//printf("\n------------\n");
	bool flag = false;
	for (int i=14;i>=0;i--) {
		if (binary[i]) {
			if (flag) printf("+");
			if (i == 1) printf("2");
			else printf("2(%s)",table[i]);
			flag = true;
		}
	}
	printf("\n");
	return 0;
}