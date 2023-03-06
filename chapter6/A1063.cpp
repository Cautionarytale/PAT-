#include<iostream>
using namespace std;
#include<set>
#include<cstdio>
set<int>st[51];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;
		for(int j=0;j<m;j++)
		{
			int val;cin>>val;
			st[i].insert(val);	
		}
	}
	int q;cin>>q;
	for(int i=0;i<q;i++)
	{
		
		int idx1,idx2;cin>>idx1>>idx2;
		int Same=0;
		int diff=st[idx2].size();
		for(auto it=st[idx1].begin();it!=st[idx1].end();it++)
		{
			if(st[idx2].find(*it)!=st[idx2].end())
			{
				Same++;
			}
			else diff++;
		}
		printf("%.1f\%\n",100.0*Same/diff);
	}
	return 0; 
}
