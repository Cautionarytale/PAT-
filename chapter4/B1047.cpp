#include<iostream>
using namespace std;
#include<cstdio>
int Hash[1010]={0};
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		int team,member,score;
		scanf("%d-%d %d",&team,&member,&score);
		Hash[team]+=score;
	}
	int k=0;
	for(int i=0;i<1010;i++)
	{
		if(Hash[i]>Hash[k])
			k=i;
	}
	cout<<k<<' '<<Hash[k];
	return 0;
}
