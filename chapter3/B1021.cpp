#include<iostream>
using namespace std;
int cnt[10]={0};
int main()
{
	string n;cin>>n;
	while(n.length()){
		int s=n.length();
		int val=n[s-1]-'0';
		cnt[val]++;
		n.pop_back();
	}
	for(int i=0;i<10;i++)
	{
		if(cnt[i])
		{
			cout<<i<<':'<<cnt[i]<<endl;
		}
	}
	return 0;
}
