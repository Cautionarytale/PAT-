#include<iostream>
using namespace std;
int main()
{
	int a,b,d;cin>>a>>b>>d;
	int sum=a+b;int ans[31];int cnt=0;
	do{
		ans[cnt++]=sum%d;
		sum/=d;
	}while(sum);
	for(int i=cnt-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}
