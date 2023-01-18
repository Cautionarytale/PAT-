#include<iostream>
using namespace std;
#include<cstdio>
int main()
{
	string str;cin>>str;
	int N=str.length();
	int n1=(N+2)/3,n3=n1,n2=N+2-n1-n3;
	for(int i=0;i<n1-1;i++)
	{
		cout<<str[i];
		for(int j=0;j<n2-2;j++)
			cout<<' ';
		cout<<str[N-i-1]<<endl;;
	}
	for(int i=0;i<n2;i++){
		cout<<str[n1+i-1];
	}
	return 0;
}

