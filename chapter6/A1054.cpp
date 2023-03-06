#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<map>
map<int,int>mp;
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int val;scanf("%d",&val);
			if(mp.find(val)!=mp.end())mp[val]++;
			else mp[val]=1;
		}
	}
	int Max=0;int k;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>Max)
		{
			Max=it->second;
			k=it->first;
		}
	}
	printf("%d",k);
	return 0;
}
