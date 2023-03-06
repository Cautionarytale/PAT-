#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
const int maxn=40010;
const int maxc=2510;
char stu[maxn][5];
vector<int>Select[maxc];
bool cmp(int a,int b){
	return strcmp(stu[a],stu[b])<0;
}
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		cin>>stu[i];
		int m;scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			int course;scanf("%d",&course);
			Select[course].push_back(i);
		}
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d %d\n",i,Select[i].size());
		sort(Select[i].begin(),Select[i].end(),cmp);
		for(auto&e:Select[i])
			printf("%s\n",stu[e]);
	}
	return 0;
}
