#include<iostream>
using namespace std;
int main()
{
	int cnt=1;
	int n;cin>>n;
	long long a,b,c;
	while(n--)
	{
		cin>>a>>b>>c;
		if(a+b>c)
			cout<<"Case #"<<cnt++<<": true"<<endl;
		else
			cout<<"Case #"<<cnt++<<": false"<<endl;
	}
	return 0;
}
