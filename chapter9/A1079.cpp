#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<cmath>
const int maxn=1e5+10;
struct Node{
	int data;
	vector<int>children;
}node[maxn];
double ans=0;
int n;
double p,r;
void dfs(int idx,int depth){
	if(node[idx].children.size()==0)
	{
		ans+=pow(1+r,depth)*node[idx].data;
		return;
	}
	for(int i=0;i<node[idx].children.size();i++)
	{
		dfs(node[idx].children[i],depth+1);
	}
}

int main()
{
	cin>>n>>p>>r;r/=100;
	for(int i=0;i<n;i++)
	{
		int num;cin>>num;
		if(num==0){
			cin>>node[i].data;
		}
		else
		{
			for(int j=0;j<num;j++)
			{
				int val;cin>>val;
				node[i].children.push_back(val);
			}
		}
	}
	dfs(0,0);
	printf("%.1f",p*ans);
	return 0;
}
