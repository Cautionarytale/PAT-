#include<iostream>
using namespace std;
#include<algorithm>
#include<queue>
const int maxn=110;
struct Node{
	int left,right;
}node[maxn];
int n,num=0;
bool isRoot[maxn]={false};
void print(int id){
	cout<<id;
	num++;
	if(num<n)cout<<' ';
	else cout<<endl;
}
void post(int root){
	if(root==-1)return;
	post(node[root].left);
	post(node[root].right);
	swap(node[root].left,node[root].right);
}
void inorder(int root){
	if(root==-1)return;
	inorder(node[root].left);
	print(root);
	inorder(node[root].right);
}
void bfs(int root){
	queue<int>q;
	q.push(root);
	while(!q.empty())
	{
		int front=q.front();q.pop();
		print(front);
		if(node[front].left!=-1)q.push(node[front].left);
		if(node[front].right!=-1)q.push(node[front].right);
	}
}


int char2num(char ch){
	if(ch=='-')return -1;
	else 
	{
		isRoot[ch-'0']=true;
		return ch-'0';
	}
}
int findRoot(){
	for(int i=0;i<n;i++)
		if(isRoot[i]==false)
			return i;
	return -1;
} 
int main()
{
	cin>>n;//getchar();
	for(int i=0;i<n;i++)
	{
		//getchar();
		char l,r;cin>>l>>r;
		node[i].left=char2num(l);
		node[i].right=char2num(r);
		if(l!=-1)isRoot[l]=true;
		if(r!=-1)isRoot[r]=true;
	}
	int root=findRoot();
	post(root);
	bfs(root);
	num=0;
	
	inorder(root);
	return 0;
}


