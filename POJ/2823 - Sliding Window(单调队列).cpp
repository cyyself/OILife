#include <cstdio>
struct DATA {
	int x;//pos
	int v;//value
	DATA() {

	}
	DATA(int _x,int _v) {
		x = _x;
		v = _v;
	}
};
struct mq {
	DATA m[1000005];
	int head;
	int tail;
	void clear() {
		head = 0;
		tail = 0;
	}
	void pop() {
		head ++;
	}
	void push(DATA a,int type) {
		if (type == 1) {
			//单减，用于求max
			while (head < tail && m[tail-1].v < a.v) tail --;
		}
		else {
			//单增，用于求min
			while (head < tail && m[tail-1].v > a.v) tail --;
		}
		m[tail++] = a;
	}
	DATA front() {
		return m[head];
	}
} q;
int a[1000005];
int n,k;
int read() {
	int ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	q.clear();
	for (int i=0;i<n;i++) {
		q.push(DATA(i,a[i]),0);
		DATA cur = q.front();
		while (cur.x <= i - k) {
			q.pop();
			cur = q.front();
		}
		if (i >= k - 1) {
			if (i != k - 1) printf(" ");
			printf("%d",cur.v);
		}
	}
	printf("\n");
	q.clear();
	for (int i=0;i<n;i++) {
		q.push(DATA(i,a[i]),1);
		DATA cur = q.front();
		while (cur.x <= i - k) {
			q.pop();
			cur = q.front();
		}
		if (i >= k - 1) {
			if (i != k - 1) printf(" ");
			printf("%d",cur.v);
		}
	}
	printf("\n");
	return 0;
}
