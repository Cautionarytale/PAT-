#include<iostream>
using namespace std;
int number[100010]={0},Hash[10010]={0};
bool flag=false;
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>number[i];
		Hash[number[i]]++;	
	}
	for(int i=0;i<n;i++)
	{
		if(Hash[number[i]]==1)
		{
			flag=true;
			cout<<number[i];
			break;
		}
	}
	if(!flag)
	cout<<"None";
	return 0;
}
