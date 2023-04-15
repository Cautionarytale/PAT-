#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
const int maxn=1010;
int n,m,k;
vector<int>Adj[maxn];
bool vis[maxn]={false};
int fa[maxn];
int now;
int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	x=Find(x);y=Find(y);
	if(x!=y)fa[x]=y;
}
int main()
{
	cin>>n>>m>>k;
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	} 
	while(k--)
	{
		cin>>now;
		iota(fa,fa+n+1,0);
		fill(vis,vis+maxn,false);
		for(int i=1;i<=n;i++)
		{
			u=i;
			for(int j=0;j<Adj[i].size();j++)
			{
				v=Adj[i][j];
				if(u==now||v==now)continue;
				Union(u,v);
			}
		}
		int block=0;
		for(int i=1;i<=n;i++)
		{
			if(i==now)continue;
			int faI=Find(i);
			if(!vis[faI])
			{
				block++;
				vis[faI]=true;
			}
		}
		cout<<block-1<<endl;
	}
	return 0;
}
