#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
const int maxn=110;
vector<int>children[maxn];
int leaf[maxn]={0};
int max_h=1;

void dfs(int idx,int depth)
{
	max_h=max(depth,max_h);
	if(children[idx].size()==0)
	{
		leaf[depth]++;
		return;
	}
	for(int i=0;i<children[idx].size();i++)
	{
		dfs(children[idx][i],depth+1);
	}
}
int main()
{
	int n,m,fa,child,num;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>fa>>num;
		for(int j=0;j<num;j++)
		{
			cin>>child;
			children[fa].push_back(child);
		}
	}
	dfs(1,1);
	for(int i=1;i<=max_h;i++)
	{
		cout<<leaf[i];
		if(i!=max_h)cout<<' ';
	}
	return 0;
}
