#include<iostream>
using namespace std;
#include<cstring>
#include<cstdio>
const int maxn=1020;
const int INF=0x3fffffff;
int n,m,k,DS;
int G[maxn][maxn];
bool vis[maxn]={false};
int d[maxn];
void dijkstra(int s){
	memset(vis,false,sizeof vis);
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n+m;i++)
	{
		int u=-1,Min=INF;
		for(int j=1;j<=n+m;j++)
		{
			if(!vis[j]&&d[j]<Min){
				u=j;Min=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++)
		{
			if(!vis[v]&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
				}
			}
		}
	}
}
int getID(string s){
	int i=0,ans=0;
	while(i<s.size())
	{
		if(s[i]!='G'){
			ans=ans*10+(s[i]-'0');
		}
		i++;
	}
	if(s[0]=='G')return n+ans;
	return ans;
}
int main(){
	cin>>n>>m>>k>>DS;
	int u,v,w;
	string s1,s2;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++)
	{
		cin>>s1>>s2>>w;
		u=getID(s1);v=getID(s2);
		G[u][v]=G[v][u]=w;
	}
	double ansD=-1,ansAvg=INF;
	int ansID=-1;
	for(int i=n+1;i<=n+m;i++)
	{
		double minD=INF,avg=0;
		dijkstra(i);
		for(int j=1;j<=n;j++)
		{
			if(d[j]>DS){
				minD=-1;
				break;
			}
			if(d[j]<minD){
				minD=d[j];
			}
			avg+=1.0*d[j]/n;
		}
		if(minD==-1)continue;
		if(minD>ansD){
			ansD=minD;
			ansID=i;
			ansAvg=avg;
		}else if(minD==ansD&&avg<ansAvg){
			ansID=i;
			ansAvg=avg;
		}
	}
	if(ansID==-1)cout<<"No Solution"<<endl;
	else{
		cout<<"G"<<ansID-n<<endl;
		printf("%.1f %.1f",ansD,ansAvg);
		//cout<<ansD<<' '<<ansAvg;
	}
	return 0;
}
