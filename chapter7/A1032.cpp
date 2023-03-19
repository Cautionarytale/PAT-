#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
struct Node{
	char data;
	int next;
	int address;
	bool flag;
}node[maxn];
int main()
{
	int s1,s2,n;cin>>s1>>s2>>n;
	for(int i=0;i<n;i++)
	{
		int add;cin>>add;
		cin>>node[add].data>>node[add].next;
		node[add].flag=false;
	}
	int p;
	for(p=s1;p!=-1;p=node[p].next)
	{
		node[p].flag=true;
	}
	for(p=s2;p!=-1;p=node[p].next)
	{
		if(node[p].flag)break;
	}
	if(p!=-1)printf("%05d",p);
	else printf("-1");
	return 0;
}
