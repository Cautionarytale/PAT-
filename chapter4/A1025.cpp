#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdio>
#include<cstring>
struct Student{
	char id[15];
	int local_rank;//³¡ÄÚÅÅÃû 
	int room;
	int score;
}s[30010];
bool cmp(Student a,Student b){
	if(a.score!=b.score)return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}
int main()
{
	int n;cin>>n;int num=0;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>s[num].id>>s[num].score;
			s[num++].room=i;
		}
		sort(s+num-m,s+num,cmp);
		s[num-m].local_rank=1;
		for(int j=num-m+1;j<num;j++)
		{
			if(s[j].score==s[j-1].score)
				s[j].local_rank=s[j-1].local_rank;
			else
				s[j].local_rank=j+1-(num-m);
		}
	}
	cout<<num<<endl;
	sort(s,s+num,cmp);
	int r=1;
	for(int i=0;i<num;i++)
	{
		if(i>0&&s[i].score!=s[i-1].score)
			r=i+1;
		cout<<s[i].id<<' '<<r<<' '<<s[i].room<<' '<<s[i].local_rank<<endl;
	}
	return 0;
}
