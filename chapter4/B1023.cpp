#include<iostream>
using namespace std;
int count[10]={0};
int main()
{
	for(int i=0;i<10;i++)
		cin>>count[i];
	for(int i=1;i<=9;i++)
	{
		if(count[i]>0)
		{
			cout<<i;
			count[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<count[i];j++)
			cout<<i;
	}
	return 0;
}
