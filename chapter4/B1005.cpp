#include<iostream>
using namespace std;
#include<algorithm>
bool cmp(int a,int b)
{
	return a>b;
}
int a[110];
bool Hash[10010]={false};
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		int m=a[i];
		while(m!=1)
		{
			if(m%2==1)m=(3*m+1)/2;
			else m/=2;
			Hash[m]=true;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
		if(Hash[a[i]]==false)
			cnt++;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(Hash[a[i]]==false)
		{
			cout<<a[i];
			cnt--;
			if(cnt>0)cout<<' ';
		}
	}
	return 0;
}
