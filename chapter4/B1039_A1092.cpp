#include<iostream>
using namespace std;
#include<map>
int main()
{
	string s1,s2;cin>>s1>>s2;
	int l1=s1.length(),l2=s2.length();
	int ans1=l1-l2;
	int cnt=0;
	map<char,int>mp;
	for(auto&e:s2)
		mp[e]++;
	for(auto&e:s1)
	{
		if(mp.count(e)&&mp[e])
		{
			mp[e]--;
			cnt++;
		}
	}
	if(cnt==l2)
		cout<<"Yes "<<ans1<<endl;
	else
		cout<<"No "<<l2-cnt<<endl;
	return 0;
}
