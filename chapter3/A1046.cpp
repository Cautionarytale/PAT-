#include<iostream>
using namespace std;
#include<algorithm>
const int maxn=100010;
int dis[maxn],edge[maxn];
int sum=0;
int main()
{
	int N;cin>>N;
	for(int i=1;i<=N;i++)
	{
		int weight;cin>>weight;
		edge[i]=weight;//¶¥µãiÓëi+1µÄ¾àÀë 
		sum+=weight;
		dis[i]=sum;
	}
	int M;cin>>M;
	while(M--)
	{
		int v1,v2;cin>>v1>>v2;
		if(v1>v2)swap(v1,v2);
		int tmp=dis[v2-1]-dis[v1-1];
		cout<<min(tmp,sum-tmp)<<endl;
	} 
	return 0;
}

