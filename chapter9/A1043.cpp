#include<iostream>
#include<vector>
using namespace std;
vector<int>origin,pre,preM,post,postM;
int n;
struct node{
	int data;
	node*left,*right;
};
void createBST(node*&root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data)createBST(root->left,data);
	else createBST(root->right,data);
}
void preOrder(node*root,vector<int>&vi){
	if(root==NULL)return;
	vi.push_back(root->data);
	preOrder(root->left,vi);
	preOrder(root->right,vi);
}
void preOrderMirror(node*root,vector<int>&vi){
	if(root==NULL)return;
	vi.push_back(root->data);
	preOrderMirror(root->right,vi);
	preOrderMirror(root->left,vi);
}
void postOrder(node*root,vector<int>&vi){
	if(root==NULL)return;
	postOrder(root->left,vi);
	postOrder(root->right,vi);
	vi.push_back(root->data);
}
//void postOrder(node*root,vector<int>&post){
//	if(!root)return;
//	postOrder(root->left,post);
//	postOrder(root->right,post);
//	post.push_back(root->data);
//}
void postOrderMirror(node*root,vector<int>&vi){
	if(root==NULL)return;
	postOrderMirror(root->right,vi);
	postOrderMirror(root->left,vi);
	vi.push_back(root->data);
}
int main()
{
	cin>>n;
	node*root=NULL;
	for(int i=0;i<n;i++)
	{
		int data;cin>>data;
		origin.push_back(data);
		createBST(root,data);
	}
	preOrder(root,pre);
	preOrderMirror(root,preM);
	postOrder(root,post);
	postOrderMirror(root,postM); 
	if(origin==pre){
		cout<<"YES"<<endl;
		for(int i=0;i<post.size();i++)
		{
			cout<<post[i];
			if(i!=post.size()-1)cout<<' ';
		}
	}
	else if(origin==preM){
		cout<<"YES"<<endl;
		for(int i=0;i<postM.size();i++)
		{
			cout<<postM[i];
			if(i!=post.size()-1)cout<<' ';
		}
	}
	else cout<<"NO"<<endl;
	return 0;
}
