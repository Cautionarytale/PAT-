#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=510;
const int INF=0x3fffffff;
int Cmax,n,sp,m;
int minNeed=INF,minRemain=INF;
int G[maxn][maxn],weight[maxn];
bool vis[maxn]={false};
int d[maxn];
int numP=0;
vector<int>pre[maxn];
vector<int>temp,path;
void dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<=n;i++)
	{
		int u=-1,Min=INF;
		for(int j=0;j<=n;j++)
		{
			if(!vis[j]&&d[j]<Min)
			{
				u=j;
				Min=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<=n;v++)
		{
			if(!vis[v]&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
				
			}
		}
	}
}
void dfs(int v){
	if(v==0){
		temp.push_back(v);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else if(remain>abs(weight[id])){
				remain-=abs(weight[id]);
			}else{
				need+=abs(weight[id])-remain;
				remain=0;
			}
		}
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			path=temp;
		}else if(need==minNeed&&remain<minRemain){
			minRemain=remain;
			path=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		dfs(pre[v][i]);
	}
	temp.pop_back();
}
int main()
{
	cin>>Cmax>>n>>sp>>m;
	int u,v;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=n;i++){
		cin>>weight[i];
		weight[i]-=Cmax/2;
	}
	for(int i=0;i<m;i++){
		cin>>u>>v;
		cin>>G[u][v];
		G[v][u]=G[u][v];
	}
	dijkstra(0);
	dfs(sp);
	cout<<minNeed<<' ';
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i];
		if(i>0)cout<<"->";
	}
	cout<<" "<<minRemain;
	return 0;
}
