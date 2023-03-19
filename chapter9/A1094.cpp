#include<iostream>
#include<vector>
using namespace std;
const int maxn=110;
vector<int>node[maxn];
int Hash[maxn]={0};
int n,m;
int fa,num,child;
void dfs(int idx,int depth){
	Hash[depth]++;
	if(node[idx].size()==0)return;
	else 
	{
		for(int i=0;i<node[idx].size();i++)
		{
			dfs(node[idx][i],depth+1);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>fa>>num;
		for(int j=0;j<num;j++)
		{
			cin>>child;
			node[fa].push_back(child);
		}
	}
	dfs(1,1);
	int maxDepth=0,maxNum=0;
	for(int i=1;i<maxn;i++)
	{
		if(Hash[i]>maxNum)
		{
			maxDepth=i;
			maxNum=Hash[i];
		}
	}
	cout<<maxNum<<' '<<maxDepth;
	return 0;
}
