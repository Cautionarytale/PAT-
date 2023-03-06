#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<vector>
const int maxn=26*26*26*10+1;
int getID(char name[]){
	int id=0;
	for(int i=0;i<3;i++)
	{
		id=id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
}
vector<int>Select[maxn];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		int course,number;scanf("%d%d",&course,&number);
		for(int j=0;j<number;j++)
		{
			char name[4];scanf("%s",name);
			int id=getID(name);
			Select[id].push_back(course);
		}
		
	}
	for(int i=0;i<n;i++)
	{
		char name[4];scanf("%s",name);
		printf("%s",name);
		int id=getID(name);
		printf(" %d",Select[id].size());
		sort(Select[id].begin(),Select[id].end());
		for(auto&e:Select[getID(name)])
		{
			printf(" %d",e);
		}
		printf("\n");
	}
	return 0;
}
