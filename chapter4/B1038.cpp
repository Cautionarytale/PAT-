#include<iostream>
using namespace std;
#include<map>
int main()
{
	int n;cin>>n;
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		int score;cin>>score;
		mp[score]++;
	}
	int m;cin>>m;m--;
	int score;cin>>score;
		if(!mp.count(score))
			cout<<'0';
		else cout<<mp[score];
	while(m--)
	{
		int score1;cin>>score1;
		if(!mp.count(score1))
			cout<<' '<<'0';
		else cout<<' '<<mp[score1];
	}
	return 0;
}
