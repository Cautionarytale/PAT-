#include<iostream>
using namespace std;
#include<algorithm>
int Hash[1010]={0};
int main()
{
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int val;cin>>val;
		Hash[val]++;
	}
	for(int i=0;i<1010;i++)
	{
		if(Hash[i]&&Hash[m-i])
		{
			if(i==m-i&&Hash[i]<=1)
				continue;
			cout<<i<<' '<<m-i<<endl;
			return 0;
		}
	}
	cout<<"No Solution"<<endl;
	return 0;
}
