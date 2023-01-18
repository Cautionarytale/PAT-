#include<iostream>
using namespace std;
#include<algorithm>
#define N 54
int start[N+1],Next[N+1],End[N+1];
char mp[5]={'S','H','C','D','J'};
int main()
{
	//iota(start,start+N+1,0);
	for(int i=1;i<=N;i++)
		start[i]=i;
	int K;cin>>K;
	for(int i=1;i<=N;i++)
		cin>>Next[i];
	while(K--)
	{
		for(int i=1;i<=N;i++)
		{
			int idx=Next[i];
			End[idx]=start[i];
		}
		copy(End,End+N+1,start);
//		for(int i=0;i<N;i++)
//			start[i]=End[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		start[i]--;
		int idx1=start[i]/13;
		int idx2=start[i]%13+1;
		if(i==1)
			cout<<mp[idx1]<<idx2;
		else
			cout<<' '<<mp[idx1]<<idx2;
	}
	
	return 0;
}
