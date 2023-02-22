#include<iostream>
using namespace std;
#include<algorithm>
struct Student{
	int id;
	int grade[4];
}s[2010];
int now;
int Rank[10000000][4]={0};
char course[4]={'A','C','M','E'};
bool cmp(Student a,Student b){
	return a.grade[now]>b.grade[now];
}
int main()
{
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].id>>s[i].grade[1]>>s[i].grade[2]>>s[i].grade[3];
		s[i].grade[0]=s[i].grade[1]+s[i].grade[2]+s[i].grade[3];
	}
	for(now=0;now<4;now++)
	{
		sort(s,s+n,cmp);
		Rank[s[0].id][now]=1;
		for(int i=1;i<n;i++)
		{
			if(s[i].grade[now]==s[i-1].grade[now])
				Rank[s[i].id][now]=Rank[s[i-1].id][now];
			else Rank[s[i].id][now]=i+1;
		}
	}
	int query;
	for(int i=0;i<m;i++)
	{
		cin>>query;
		if(Rank[query][0]==0)
			cout<<"N/A"<<endl;
		else
		{
			int k=0;
			for(int j=0;j<4;j++)
			{
				if(Rank[query][j]<Rank[query][k])
					k=j;
			}
			cout<<Rank[query][k]<<' '<<course[k]<<endl;
		}
	}
	return 0;
}
