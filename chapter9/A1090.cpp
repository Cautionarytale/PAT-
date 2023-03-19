#include<iostream>
using namespace std;
#include<cstdio>
#include<vector>
#include<cmath>
const int maxn=1e5+10;
vector<int>children[maxn];
int fa,root;
int n;
double p,r;
int maxDepth=0,num=0;
void dfs(int idx,int depth)
{
	if(children[idx].size()==0)
	{
		if(depth>maxDepth){
			maxDepth=depth;
			num=1;
		}else if(depth==maxDepth){
			num++;
		}
		return;
	}
	for(int i=0;i<children[idx].size();i++)
	{
		dfs(children[idx][i],depth+1);
	}
}

int main()
{
	cin>>n>>p>>r;r/=100;
	for(int i=0;i<n;i++)
	{
		cin>>fa;
		if(fa==-1)root=i;
		else children[fa].push_back(i);
	}
	dfs(root,0);
	printf("%.2f %d",p*pow(1+r,maxDepth),num);
	
	return 0;
}
