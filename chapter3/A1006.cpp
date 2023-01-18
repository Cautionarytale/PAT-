#include<iostream>
using namespace std;
#include<cstdio>
struct pNode{
	char name[20];
	int h1,m1,s1;
	int h2,m2,s2;
}earliest,latest,temp;
bool earlier(pNode p1,pNode p2){
	if(p1.h1!=p2.h1)return p1.h1<=p2.h1;
	else if(p1.m1!=p2.m1)return p1.m1<=p2.m1;
	else return p1.s1<=p2.s1;
}
bool later(pNode p1,pNode p2){
	if(p1.h2!=p2.h2)return p1.h2>=p2.h2;
	else if(p1.m2!=p2.m2)return p1.m2>=p2.m2;
	else return p1.s2>=p2.s2;
}
void init()
{
	earliest.h1=25;earliest.m1=61;earliest.s1=61;
	latest.h2=-1;latest.m2=-1;latest.s2=-1;
}
int main()
{
	init();
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d",temp.name,&temp.h1,&temp.m1,&temp.s1,&temp.h2,&temp.m2,&temp.s2);
		if(earlier(temp,earliest))earliest=temp;
		if(later(temp,latest))latest=temp;
	}
	printf("%s %s",earliest.name,latest.name);
	return 0;
}
