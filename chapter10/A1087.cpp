#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int inf=0x3fffffff;
const int maxn=1001;
int n,k,cost[maxn][maxn],d[maxn],H[maxn],anshappy=-1,ansavg=-1,num[maxn]={0};
string st;
bool vis[maxn]={false};
vector<int> temp,path,pre[maxn];
map<string,int> strToint;
map<int,string> intTostr;
void dijkstra(int s)
{
	fill(d,d+maxn,inf);
	d[s]=0;
	num[s]=1;
	for(int i=0;i<n;i++)
	{
		int min=inf,u=-1;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1)break;
		vis[u]=true;
		for(int v=0;v<n;v++)
	     {
	     	if(vis[v]==false&&cost[u][v]!=inf)
	     	{
	     		if(cost[u][v]+d[u]<d[v])
	     		{
	     			pre[v].clear();
	     			pre[v].push_back(u);
	     			d[v]=cost[u][v]+d[u];
	     			num[v]=num[u];
				 }
				 else if(cost[u][v]+d[u]==d[v])
				 {
				 	pre[v].push_back(u);
				 	num[v]+=num[u];
				 }
			 }
		 }
	}
}
void DFS(int v)
{
	if(v==0)
	{
		temp.push_back(v);
		int happy=0,avg;
		for(int i=temp.size()-1;i>=0;i--)
		{
			happy+=H[temp[i]];
		}
		avg=happy/(temp.size()-1);
		if(happy>anshappy)
        {
        	path=temp;
        	anshappy=happy;
        	ansavg=avg;
		}
		else if(happy==anshappy&&avg>ansavg)
		{
			path=temp;
        	ansavg=avg;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++)
	{
		DFS(pre[v][i]);
	}
	temp.pop_back();
}
int main()
{
	cin>>n>>k>>st;
	strToint[st]=0;
	intTostr[0]=st;
	string city,city1,city2;
	int happy,c1,c2,co;
	H[0]=0;
	for(int i=1;i<n;i++)
	{
		cin>>city>>happy;
		strToint[city]=i;
		intTostr[i]=city;
		H[i]=happy;
	}
	fill(cost[0],cost[0]+maxn*maxn,inf);
	for(int i=0;i<k;i++)
	{
		cin>>city1>>city2>>co;
		c1=strToint[city1];
		c2=strToint[city2];
		cost[c1][c2]=cost[c2][c1]=co;
	}
	dijkstra(0);
	int id=strToint["ROM"];
	DFS(id);
	printf("%d %d %d %d\n",num[id],d[id],anshappy,ansavg);
	for(int i=path.size()-1;i>=0;i--)
	{
		cout<<intTostr[path[i]];
		if(i!=0)
		printf("->");
	}
	
}

