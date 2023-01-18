#include<iostream>
using namespace std;
int main()
{
	int N;cin>>N;
	int a1,b1,a2,b2;
	bool f1,f2;
	int ans1=0,ans2=0;
	while(N--)
	{	
		cin>>a1>>b1>>a2>>b2;
		f1=a1+a2==b1;
		f2=a1+a2==b2;
		if((f1&&f2)||!(f1||f2))
		{}
		else if(f1&&!f2)
			ans2++;
		else if(!f1&&f2)
			ans1++;		
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}
