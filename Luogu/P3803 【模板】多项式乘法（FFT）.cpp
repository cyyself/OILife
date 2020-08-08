#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
const double pi = acos((double)-1);
const int maxn = 1<<22;//2e6
namespace fft {
	complex <double> omega[maxn];
	void init(int n) {
		for (int i=0;i<n;i++) {
			omega[i] = complex<double>(cos(2*pi*i/n),sin(2*pi*i/n));
		}
	}
	void transform(complex<double> *a,int n,bool inv) {
		int k = 0;
		while ((1 << k) < n) k ++;
		for (int i=0;i<n;i++) {
			int t = 0;
			for (int j=0;j<k;j++) if (i & (1 << j)) t |= (1 << (k - j - 1));
			if (i < t) swap(a[i],a[t]);
		}
		for (int l=2;l<=n;l*=2) {
			int m = l / 2;
			for (auto *p=a;p != a + n;p += l) {
				for (int i=0;i<m;i++) {
					complex<double> t = (inv?conj(omega[n/l*i]):omega[n/l*i]) * p[m+i];
					p[m+i] = p[i] - t;
					p[i] += t;
				}
			}
		}
	}
	void dft(complex<double> *a,int n) {
		transform(a,n,false);
	}
	void idft(complex<double> *a,int n) {
		transform(a,n,true);
		for (int i=0;i<n;i++) a[i] /= n;
	}
}
struct poly {
	vector <int> vec;
	friend poly operator * (const poly &a,const poly &b) {
		int n = 1;
		while (n < a.vec.size() + b.vec.size()) n <<= 1;
		static complex <double> c1[maxn],c2[maxn];
		for (int i=0;i<a.vec.size();i++) c1[i].real(a.vec[i]);
		for (int i=0;i<b.vec.size();i++) c2[i].real(b.vec[i]);
		fft::init(n);
		fft::dft(c1,n);
		fft::dft(c2,n);
		for (int i=0;i<n;i++) c1[i] *= c2[i];
		fft::idft(c1,n);
		poly res;
		for (int i=0;i<a.vec.size()+b.vec.size()-1;i++) res.vec.push_back((int)floor(c1[i].real()+0.5));
		return res;
	}
};
int main() {
	poly f,g;
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) {
		int t;
		scanf("%d",&t);
		f.vec.push_back(t);
	}
	for (int i=0;i<=m;i++) {
		int t;
		scanf("%d",&t);
		g.vec.push_back(t);
	}
	poly res = f * g;
	for (auto x:res.vec) printf("%d ",x);
	printf("\n");
	return 0;
}
