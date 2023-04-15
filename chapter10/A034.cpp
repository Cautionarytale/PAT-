#include<iostream>
using namespace std;
#include<map>
const int maxn=2010;
const int INF=0x3fffffff;
int N,threshold;
map<int,string>int2string;
map<string,int>string2int;
map<string,int>Gang;//头目名字->人数
int numPerson=0;
int G[maxn][maxn]={0},weight[maxn]={0};
bool vis[maxn]={false};
int getID(string s){
	if(string2int.find(s)!=string2int.end()){
		return string2int[s];
	}else{
		string2int[s]=numPerson;
		int2string[numPerson]=s;
		return numPerson++;
	}
} 
void dfs(int cur,int&head,int&numMember,int&total){
	vis[cur]=true;
	numMember++;
	if(weight[cur]>weight[head])head=cur;
	for(int i=0;i<numPerson;i++){
		if(G[cur][i]>0){
			total+=G[cur][i];
			G[cur][i]=G[i][cur]=0;
			if(!vis[i]){
				
				dfs(i,head,numMember,total);
			}
		}
	}
}
void dfsTraverse(){
	for(int i=0;i<numPerson;i++)
	{
		if(!vis[i]){
			int head=i,numMember=0,total=0;
			dfs(i,head,numMember,total);
			if(numMember>2&&total>threshold)
			{
				Gang[int2string[head]]=numMember;
			}
		}
	}
}
int main(){
	cin>>N>>threshold;
	string s1,s2;
	int time;
	for(int i=0;i<N;i++)
	{
		cin>>s1>>s2>>time;
		int id1=getID(s1),id2=getID(s2);
		G[id1][id2]+=time;G[id2][id1]+=time;
		weight[id1]+=time;weight[id2]+=time; 
	}
	dfsTraverse();
	cout<<Gang.size()<<endl;
	for(auto it=Gang.begin();it!=Gang.end();it++)
	{
		cout<<it->first<<' '<<it->second<<endl;
	}
	return 0;
}
