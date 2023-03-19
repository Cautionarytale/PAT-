#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<cstdio>
const int MAXN=110;
struct Node{
	int data;
	vector<int>children;
}node[MAXN];
int n,m,S;
vector<int>path;
vector<vector<int>>ans;
void dfs(int idx,vector<int>path,int sum)
{
	if(sum>S)return;
	if(sum==S)
	{
		if(node[idx].children.size()!=0)return;
		ans.push_back(path);
		return;
	}
	for(int i=0;i<node[idx].children.size();i++)
	{
		int child=node[idx].children[i];
		path.push_back(node[child].data);
		dfs(child,path,sum+node[child].data);
		path.pop_back();
	}
}
int main()
{
	cin>>n>>m>>S;
	for(int i=0;i<n;i++)
	{
		cin>>node[i].data;
	}
	int fa,num,child;
	for(int i=0;i<m;i++)
	{
		cin>>fa>>num;
		for(int j=0;j<num;j++)
		{
			cin>>child;
			node[fa].children.push_back(child);
		}
	}
	path.push_back(node[0].data);
	dfs(0,path,node[0].data);
	sort(ans.begin(),ans.end(),greater<vector<int>>());
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0];
		for(int j=1;j<ans[i].size();j++)
			cout<<' '<<ans[i][j];
		cout<<endl;
	}
	return 0;
}
