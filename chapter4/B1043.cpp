#include<iostream>
using namespace std;
int Hash[6]={0};
char dic[6]={'P','A','T','e','s','t'};
int main()
{
	int sum=0;
	string s;cin>>s;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<6;j++)
		{
			if(s[i]==dic[j])
			{
				sum++;
				Hash[j]++;	
			}
		}
	}
	while(sum)
	{
		for(int i=0;i<6;i++)
		{
			if(Hash[i])
			{
				Hash[i]--;
				cout<<dic[i];
				sum--;
			}
		}
	}
	return 0;
}
