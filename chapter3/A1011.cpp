#include<iostream>
using namespace std;
char s[3]={'W','T','L'};
#include<vector>
#include<algorithm>
#include<cstdio>
float Max(float a,float b,float c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main()
{
	char ans[3];
	float ret=1;
	for(int i=0;i<3;i++)
	{
		float w,t,l;cin>>w>>t>>l;
		if(w==Max(w,t,l)) ans[i]='W';
		else if(t==Max(w,t,l)) ans[i]='T';
		else ans[i]='L';
		ret*=Max(w,t,l);
	}
	ret*=0.65;
	ret-=1;
	ret*=2;
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' ';
	printf("%.2f",ret);
	return 0;
}
