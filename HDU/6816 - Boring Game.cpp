#include <bits/stdc++.h>
using namespace std;
int per[2049];
int mt[200][2][1025];
struct Matrix {
	vector <int> v[1025];
	int w,h;
	Matrix(int k) {
		w = 1;
		h = 2 << k;
		for (int i=1;i<=h;i++) v[1].push_back(i);
	}
	void change() {
		while (h > 2) {
			for (int i=w+1;i<=w*2;i++) {
				for (int j=h/2;j<h;j++) v[i].push_back(v[i-w][j]);
				v[i-w].resize(h/2);
				reverse(v[i-w].begin(),v[i-w].end());
			}
			int l = 1,r = w;
			while (l < r) {
				swap(v[l],v[r]);
				l ++;
				r --;
			}
			w <<= 1;
			h >>= 1;
		}
	}
};
void do_per(int k) {
	Matrix mt(k);
	mt.change();
	int ptr = 1;
	for (int i=0;i<mt.h;i++) for (int j=1;j<=mt.w;j++) per[ptr++] = mt.v[j][i];
}
int a[409605],ans[409605];
void test() {
	for (int k=1;k<=4;k++) {
		do_per(k);
		for (int i=1;i<=(2<<k);i++) printf("%d ",per[i]);
		printf("\n");
	}
}
int main() {
	//test();
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n*(2<<k);i++) scanf("%d",&a[i]);
		do_per(k);
		for (int i=(1<<k);i>=1;i--) {
			if (i & 1) {
				int num = per[i] * n;
				for (int j=0;j<=n-1;j++) for (int kk=0;kk<=1;kk++) mt[j][kk][i] = num --;
			}
			else {
				int num = per[(1<<k)+i] * n;
				for (int j=n-1;j>=0;j--) for (int kk=1;kk>=0;kk--) mt[j][kk][i] = num --;
			}
		}
		int ptr = 1;
		for (int i=0;i<n;i++) for (int j=0;j<2;j++) for (int kk=1;kk<=(1<<k);kk++) ans[ptr++] = a[mt[i][j][kk]];
		for (int i=1;i<=n*(2<<k);i++) printf("%d%c",ans[i],i==n*(2<<k)?'\n':' ');
	}
	return 0;
}
