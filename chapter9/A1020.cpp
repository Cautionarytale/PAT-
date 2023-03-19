#include<iostream>
using namespace std;
#include<queue>
const int maxn=50;
struct node{
	int data;
	node*left,*right;
};
int pre[maxn],in[maxn],post[maxn];
int n;
int num=0;
node*createTree(int inL,int inR,int postL,int postR)
{
	if(postL>postR){
		return NULL;
	}
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(in[k]==post[postR])
			break;
	}
	int numLeft=k-inL;
	node*root=new node;
	root->data=post[postR];
	root->left=createTree(inL,k-1,postL,postL+numLeft-1);
	root->right=createTree(k+1,inR,postL+numLeft,postR-1);
	return root;
}
void bfs(node*root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node*top=q.front();q.pop();
		cout<<top->data;
		num++;
		if(num<n)cout<<' ';
		if(top->left)q.push(top->left);
		if(top->right)q.push(top->right);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>post[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node*root=createTree(0,n-1,0,n-1);
	bfs(root);
	return 0;
}
