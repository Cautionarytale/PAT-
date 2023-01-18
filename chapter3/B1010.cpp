#include<iostream>
using namespace std;
int a[1010];
#include<cstdio>
int main()
{
	int k,e,cnt=0;
	while(scanf("%d%d",&k,&e)!=EOF)
	{
		a[e]=k;
	}
	a[0]=0;
	for(int i=1;i<1010;i++)
	{
		a[i-1]=i*a[i];
		a[i]=0;
		if(a[i-1])cnt++;
	}
	if(!cnt)cout<<"0 0"<<endl;
	else
	{
		for(int i=1009;i>=0;i--)
		{
			if(a[i])
			{
				cout<<a[i]<<' '<<i;
				cnt--;
				if(cnt)cout<<' ';
			}
		}
	}
	return 0;
}
