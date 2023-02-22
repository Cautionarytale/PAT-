#include<iostream>
using namespace std;
#include<cstdio> 
#include<cstring>
#include<algorithm>
struct student{
	char id[15];
	int de,cai,sum,level;
}s[100010];
bool cmp(student a,student b){
	if(a.level!=b.level)return a.level<b.level;
	else if(a.sum!=b.sum)return a.sum>b.sum;
	else if(a.de!=b.de)return a.de>b.de;
	else return strcmp(a.id,b.id)<0;
}
int main()
{
	int N,L,H;scanf("%d%d%d",&N,&L,&H);
	int cnt=0;
	for(int i=0;i<N;i++)
	{
	//	char id[15];int de,cai;
		scanf("%s %d %d",s[i].id,&s[i].de,&s[i].cai);
	//	s[i].id=id;s[i].de=de;s[i].cai=cai;
		s[i].sum=s[i].de+s[i].cai;
		if(s[i].de<L||s[i].cai<L)
		{
			s[i].level=5;
		}
		else if(s[i].de>=H&&s[i].cai>=H)
		{
			s[i].level=1;cnt++;
		}
		else if(s[i].de>=H&&s[i].cai<H)
		{
			s[i].level=2;cnt++;
		}
		else if(s[i].de<H&&s[i].cai<H&&s[i].de>=s[i].cai)
		{
			s[i].level=3;cnt++;
		}
		else{
			s[i].level=4;cnt++;
		}
	}
	sort(s,s+N,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%s %d %d\n",s[i].id,s[i].de,s[i].cai);
	}
	return 0;
}
