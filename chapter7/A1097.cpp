#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
#include<cstdio>
const int maxn=1e5+10;
const int maxN=1e6+10;
struct Node{
	int address,data,next;
	int order;
}node[maxn];
bool isExist[maxN];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main()
{
	memset(isExist,false,sizeof isExist);
	for(int i=0;i<maxn;i++)
	{
		node[i].order=2*maxn;
	}
	int cntValid=0,cntRemoved=0;
	int Begin,n;cin>>Begin>>n;
	int p=Begin;
	for(int i=0;i<n;i++)
	{
		int add;cin>>add;
		node[add].address=add;
		cin>>node[add].data>>node[add].next;
	}
	while(p!=-1)
	{
		if(isExist[abs(node[p].data)]==false){
			isExist[abs(node[p].data)]=true;
			node[p].order=cntValid++;
		}
		else{
			node[p].order=maxn+cntRemoved++;
		}
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	int cnt=cntValid+cntRemoved;
	for(int i=0;i<cnt;i++)
	{
		if(i!=cntValid-1&&i!=cnt-1)
		{
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
			
		}
		else{
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}
	}
	return 0;
}
