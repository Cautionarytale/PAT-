#include<iostream>
using namespace std;
long long cal(long long X,long long DX)
{
	int cnt=1;
	long long PX=0;
	while(X)
	{
		if(X%10==DX)
		{
			PX+=DX*cnt;
			cnt*=10;
		}
		X/=10;
	}
	return PX;
} 
int main()
{
	long long A,DA,B,DB;
	cin>>A>>DA>>B>>DB; 
	long long PA=cal(A,DA);
	long long PB=cal(B,DB);
	cout<<PA+PB<<endl;
	return 0;
}
