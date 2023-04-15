#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int n,m,st,ed;
int G[maxn][maxn],cost[maxn][maxn];
int d[maxn];
int MinCost=INF;
bool vis[maxn]={false};
vector<int>pre[maxn];
vector<int>path,temp;
void Dijkstra(int s){
	d[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,Min=INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&Min>d[j])
			{
				u=j;
				Min=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(!vis[v]&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}
void dfs(int s){
	if(s==st)
	{
		temp.push_back(s);
		int cc=0;
		for(int i=temp.size()-1;i>0;i--)
		{
			int id1=temp[i],id2=temp[i-1];
			cc+=cost[id1][id2];
		}
		if(cc<MinCost)
		{
			MinCost=cc;
			path=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	for(int i=0;i<pre[s].size();i++)
	{
		dfs(pre[s][i]);
	}
	temp.pop_back();
}
int main(){
	cin>>n>>m>>st>>ed;
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	fill(d,d+maxn,INF);
	int u,v,w,c;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w>>c;
		G[u][v]=G[v][u]=w;
		cost[u][v]=cost[v][u]=c;
	}
	Dijkstra(st);
	dfs(ed);
	for(int i=path.size()-1;i>=0;i--)
	{
		cout<<path[i]<<' ';
	}
	cout<<d[ed]<<' '<<MinCost;
	return 0;
}
