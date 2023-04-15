#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
int n,L;
bool inq[maxn]={false};
struct Node{
	int id,layer;
};
vector<Node>Adj[maxn];
int BFS(int s){
	int ret=0;
	queue<Node>q;
	Node node;
	node.id=s;node.layer=0;
	q.push(node);inq[s]=true;
	while(!q.empty()){
		Node topNode=q.front();q.pop();
		int id=topNode.id;
		for(int i=0;i<Adj[id].size();i++)
		{
			Node temp=Adj[id][i];temp.layer=topNode.layer+1;
			if(!inq[temp.id]&&temp.layer<=L)
			{
				q.push(temp);
				inq[temp.id]=true;
				ret++;
			}
		}
	}
	return ret;
}
int main(){
	cin>>n>>L;
	int num,followed;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		for(int j=0;j<num;j++)
		{
			cin>>followed;
			Node node;node.id=i;
			Adj[followed].push_back(node);
		}
	}	
	int query,id;
	cin>>query;
	while(query--){
		cin>>id;
		memset(inq,false,sizeof inq);
		cout<<BFS(id)<<endl;
	}
	return 0;
}
