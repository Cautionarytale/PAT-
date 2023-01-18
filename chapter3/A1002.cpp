#include<iostream>
#include<cstdio>
using namespace std;
float a[1010],b[1010],c[1010];
int main()
{
	int cnt=0;
	int n1;cin>>n1;
	for(int i=0;i<n1;i++)
	{
		int e;float k;
		scanf("%d%f",&e,&k);
		a[e]=k;
	}
	int n2;cin>>n2;
	for(int i=0;i<n2;i++)
	{
		int e;float k;
		scanf("%d%f",&e,&k);
		b[e]=k;
	}
	for(int i=0;i<1010;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i])cnt++;
	}
	cout<<cnt;
	for(int i=1009;i>=0;i--)
	{
		if(c[i])
		{
			printf(" %d %.1f",i,c[i]);
		}
	}
	return 0;
}
