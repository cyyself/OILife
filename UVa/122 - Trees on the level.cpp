//算法竞赛入门经典P151，二叉树
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define maxn 10000
using namespace std;
struct Node{
	bool have_value;
	int v;
	Node *L, *R;
	Node():have_value(false),L(NULL),R(NULL){}
};
bool failed;
Node *root;
char s[maxn];
void addNode(int v,char* s){
	Node *last = root;
	for (int i=0;i<strlen(s);i++){
		if (s[i] == 'L'){
			if (last->L == NULL) last->L = new Node;
			last = last->L;
		}
		if (s[i] == 'R'){
			if (last->R == NULL) last->R = new Node;
			last = last->R;
		}
	}
	if (last->have_value) failed = true;
	last->v = v;
	last->have_value = true;
}
void delnode(Node* n){
	if (n == NULL) return;
	delnode(n->L);
	delnode(n->R);
	delete n;
}
int main(){
	while(1){
		root = new Node;
		failed = false;
		while(1){
			if (scanf("%s",&s) != 1) return 0;
			if (!strcmp(s,"()")) break;
			int v;
			sscanf(&s[1],"%d",&v);
			addNode(v,strchr(s,',')+1);
		}
		string output = "";
		queue <Node*> q;
		q.push(root);
		while(!q.empty()){
			Node *top = q.front();
			q.pop();
			if (!top->have_value){
				failed = true;
				break;
			}
			char t[maxn];
			sprintf(t,"%d ",top->v);
			output += t;
			if (top->L != NULL) q.push(top->L);
			if (top->R != NULL) q.push(top->R);
		}

		if (failed) printf("not complete\n");
		else {
			output[output.length()-1] = "";
			cout << output << endl;
		}
		delnode(root);
	}
	return 0;
}
//(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
//(3,L) (4,R) ()