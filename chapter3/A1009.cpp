#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a[1010],b[1010],c[2010];
//bool d[2010];
int main()
{
	memset(a,1010,0);
	memset(b,1010,0);
	memset(c,2010,0);
//memset(d,2010,0);
	int cnt=0;
	int n1;cin>>n1;
	for(int i=0;i<n1;i++)
	{
		int e;double k;
		scanf("%d%lf",&e,&k);
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
		for(int j=0;j<1010;j++)
		{
			if(a[i]&&b[j])
			{
				c[i+j]+=a[i]*b[j];
			}
		}
	}
	for(int i=0;i<=2000;i++)
		if(c[i])cnt++;
	cout<<cnt;
	for(int i=2000;i>=0;i--)
	{
		if(c[i])
		{
			printf(" %d %.1f",i,c[i]);
		}
	}
	return 0;
}
