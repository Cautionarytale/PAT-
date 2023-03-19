#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
struct Node{
	int address;
	int data;
	int next;
	bool flag;
}node[maxn];
bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false)
		return a.flag>b.flag;
	return a.data<b.data;
}
int main()
{
	for(int i=0;i<maxn;i++)
	{
		node[i].flag=false;
	}
	int n,Begin;cin>>n>>Begin;
	for(int i=0;i<n;i++)
	{
		int add;cin>>add;
		node[add].address=add;
		cin>>node[add].data>>node[add].next;
	}
	int p=Begin;
	int cnt=0;
	while(p!=-1){
		node[p].flag=true;
		cnt++;
		p=node[p].next;
	}
	if(cnt==0)printf("0 -1\n");
	else
	{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",cnt,node[0].address);
		for(int i=0;i<cnt-1;i++)
		{
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}
		printf("%05d %d -1",node[cnt-1].address,node[cnt-1].data);
	}
	return 0;
}
