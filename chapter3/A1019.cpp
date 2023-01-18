#include<iostream>
using namespace std;
bool palindromic(int*a,int n){
	for(int i=0;i<=n/2;i++)
		if(a[i]!=a[n-i-1])
			return false;
	return true;
}


int main()
{
	int number;cin>>number;
	int d;cin>>d;
	int ans[41];int cnt=0;
	do{
		ans[cnt++]=number%d;
		number/=d;
	}while(number);
	if(palindromic(ans,cnt))
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	cout<<ans[cnt-1];
	for(int i=cnt-2;i>=0;i--)
		cout<<' '<<ans[i];	
	return 0;
}
