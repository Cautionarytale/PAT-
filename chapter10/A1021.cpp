#include<iostream>
using namespace std;
#include<numeric>
#include<vector>
#include<set>
#include<algorithm>
const int maxn=100010;
const int INF=0x3fffffff;
int maxH=0;
//set<int>temp,ans;
vector<int>temp,ans;

vector<int>Adj[maxn];
bool isRoot[maxn]={false};
int fa[maxn];

int Find(int x){
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	int fax=Find(x);int fay=Find(y);
	if(x!=y)fa[fax]=fay;
}
void init(int n){
	//iota(fa,fa+n+1,0);
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
int calBlock(int n)
{
	int block=0;
	for(int i=1;i<=n;i++)
	{
		isRoot[Find(i)]=true;
	}
	for(int i=1;i<=n;i++)
	{
		block+=isRoot[i];
	}
	return block;
}
void dfs(int u,int h,int pre){
	if(h>maxH){
		temp.clear();
		//temp.insert(u);
		temp.push_back(u);
		maxH=h;
	}else if(h==maxH){
		//temp.insert(u);
		temp.push_back(u);
	}
		for(int i=0;i<Adj[u].size();i++)
		{
			int v=Adj[u][i];
			if(v==pre)continue;
			dfs(v,h+1,u);
		}
	
}
int main(){
	int n;
	cin>>n;
	init(n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
		Union(u,v);
	}
	int block=calBlock(n);
	if(block!=1){
		cout<<"Error: "<<block<<" components"<<endl;
	}else{
		dfs(1,1,-1);
//		for(auto it=temp.begin();it!=temp.end();it++)
//		{
//			ans.insert(*it);
//		}
		ans=temp;
		//temp.clear();
		dfs(ans[0],1,-1);
//		for(auto it=temp.begin();it!=temp.end();it++)
//		{
//			ans.insert(*it);
//		}
		for(int i=0;i<temp.size();i++)ans.push_back(temp[i]);
		sort(ans.begin(),ans.end());
		cout<<ans[0]<<endl;
		for(int i=1;i<ans.size();i++){
			//cout<<*it<<endl;
			if(ans[i]!=ans[i-1])cout<<ans[i]<<endl;
		}
	}
	return 0;
}
