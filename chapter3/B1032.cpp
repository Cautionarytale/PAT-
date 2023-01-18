#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
const int MAXN=100010;
int main()
{
	vector<int>v(MAXN,0);
	int n;cin>>n;
	if(n==1)
	{
		int idx,score;
		cin>>idx>>score;
		cout<<idx<<' '<<score;
	}
	else
	{
		while(n--)
	{
		int idx;int score;
		cin>>idx>>score;
		v[idx]+=score;
	}
	auto biggest=max_element(v.begin(),v.end());
	cout<<distance(v.begin(),biggest)<<' '<<*biggest;
	}
	
	return 0;
}
