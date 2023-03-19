#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdio>
const int maxn=1e5+10;
int Begin,n,k;
struct Node{
	int address,data;
	int order;
	int next;
}node[maxn];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main()
{
	cin>>Begin>>n>>k;
	int r=0;
	for(int i=0;i<maxn;i++)
	{
		node[i].order=maxn;
	}
	for(int i=0;i<n;i++)
	{
		int add;cin>>add;
		cin>>node[add].data>>node[add].next;
		node[add].address=add;
	}
	int p=Begin;
	while(p!=-1){
		node[p].order=r++;
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	n=r;//样例中存在无效节点 
	for(int i=0;i<n/k;i++)
	{
		for(int j=(i+1)*k-1;j>i*k;j--)
		{
			printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
		}
		printf("%05d %d ",node[i*k].address,node[i*k].data);
		if(i<n/k-1){
			printf("%05d\n",node[(i+2)*k-1].address);
		}
		else
		{
			if(n%k==0)printf("-1\n");
			else{
				printf("%05d\n",node[(i+1)*k].address);
				for(int j=(i+1)*k;j<n;j++)
				{
					printf("%05d %d ",node[j].address,node[j].data);
					if(j<n-1)printf("%05d\n",node[j].next);
					else printf("-1\n");
				}
			}
		}
	}
	return 0;
}
