#include<iostream>
using namespace std;
#include<cmath>
float a[1010];
void init()
{
	a[0]=1.0;
	for(int i=1;i<=1000;i++)
	{
		a[i]=a[i-1]+2*(2*i+1);
	} 
}
void print(int idx,char ch)
{
	int x=sqrt((a[idx]+1.0)/2.0);
	int bottom = 2*x-1;
	for(int i=bottom;i>=1;i-=2)
	{
		for(int j=0;j<(bottom-i)/2;j++)
			cout<<' ';
		for(int j=0;j<i;j++)
			cout<<ch;
		cout<<endl;
	}
	
	for(int i=3;i<=bottom;i+=2)
	{
		for(int j=0;j<(bottom-i)/2;j++)
			cout<<' ';
		for(int j=0;j<i;j++)
			cout<<ch;
		cout<<endl;
	}
	
}
int main()
{
	init();
	int n;cin>>n;
	char ch;cin>>ch;
	int idx,cnt;
	for(int i=0;i<1000;i++)
	{
		if(a[i]<=n&&a[i+1]>n)
		{
			idx=i;cnt=n-a[i];
		}
	}
	print(idx,ch);
	cout<<cnt<<endl;
	return 0;
}
