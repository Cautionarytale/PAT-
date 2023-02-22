#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
const int MAXN=100010;
const int MOD=1000000007;
int lp[MAXN]={0}; 
int main()
{
	string s;cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(i>0)lp[i]=lp[i-1];
		if(s[i]=='P')lp[i]++;
	}
	int ans=0,lr=0;
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]=='T')lr++;
		else if(s[i]=='A')
			ans=(ans+lp[i]*lr)%MOD;
	}
	cout<<ans;
	return 0;
}

