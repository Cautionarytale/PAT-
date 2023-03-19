#include<iostream>
using namespace std;
#include<algorithm>
#include<queue>
const int maxn=110;
struct Node{
	int data;
	int left,right;
}node[maxn];
int origin[maxn];
int n,idx=0;

void inorder(int root){
	if(root==-1)return;
	inorder(node[root].left);
	node[root].data=origin[idx++];
	inorder(node[root].right);
}
void bfs(int root)
{
	int num=0;
	queue<int>q;q.push(root);
	while(!q.empty())
	{
		int front=q.front();q.pop();
		cout<<node[front].data;
		if(++num<n)cout<<' ';
		if(node[front].left!=-1)q.push(node[front].left);
		if(node[front].right!=-1)q.push(node[front].right);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>node[i].left>>node[i].right;
	}
	for(int i=0;i<n;i++)
		cin>>origin[i];
	sort(origin,origin+n);
	inorder(0);
	bfs(0);
	return 0;
}

