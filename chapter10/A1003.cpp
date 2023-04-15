#include<iostream>
#include<cstring>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int N,M,st,ed;
int G[maxn][maxn];
bool vis[maxn]={false};
int weight[maxn]={0};
int num[maxn]={0},W[maxn]={0},d[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	//vis[s]=true;
	W[s]=weight[s];
	num[s]=1;
	d[s]=0;
	for(int i=0;i<N;i++)
	{
		int u=-1,Min=INF;
		for(int j=0;j<N;j++)
		{
			if(!vis[j]&&Min>d[j])
			{
				u=j;Min=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<N;v++)
		{
			if(!vis[v]&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					num[v]=num[u];
					W[v]=W[u]+weight[v];
				}else if(d[u]+G[u][v]==d[v]){
					if(W[u]+weight[v]>W[v])
					{
						W[v]=W[u]+weight[v];
					}
					num[v]+=num[u];
				}
			}
		}
	}
}
int main(){
	fill(G[0],G[0]+maxn*maxn,INF);
	cin>>N>>M>>st>>ed;
	int w;
	for(int i=0;i<N;i++)
	{
		cin>>w;
		weight[i]=w;
	}
	int u,v;
	for(int i=0;i<M;i++)
	{
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=w;
	}
	Dijkstra(st);
	cout<<num[ed]<<' '<<W[ed];
	return 0;
}
