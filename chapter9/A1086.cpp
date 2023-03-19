#include<iostream>
using namespace std;
#include<stack>
const int maxn=50;
int n;
int num=0;
int pre[maxn],in[maxn],post[maxn];
int idxPre=0,idxIn=0,idxPost=0;
struct node{
	int data;
	node*left,*right;
};
node*createTree(int preL,int preR,int inL,int inR)
{
	if(preL>preR)
	{
		return NULL;
	}
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(in[k]==pre[preL])
			break;
	}
	int numLeft=k-inL;
	node*root=new node;
	root->data=pre[preL];
	root->left=createTree(preL+1,preL+numLeft,inL,k-1);
	root->right=createTree(preL+numLeft+1,preR,k+1,inR);
	return root;
}
void Post(node*root){
	if(!root)return;
	Post(root->left);
	Post(root->right);
	if(num!=0)cout<<' ';
	cout<<root->data;
	num++;
	
}
int main()
{
	int n;cin>>n;
	string op;int val;
	stack<int>stk;
	for(int i=0;i<2*n;i++)
	{
		cin>>op;
		if(op=="Push")
		{
			cin>>val;
			pre[idxPre++]=val;
			stk.push(val);
		}
		else 
		{
			int top=stk.top();stk.pop();
			in[idxIn++]=top;
		}
	}
	node*root=createTree(0,n-1,0,n-1);
	Post(root);	
	return 0;
}
