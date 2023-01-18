#include<iostream>
using namespace std;
int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};

int main()
{
	int n;cin>>n;
	bool flag1=true;
	while(n--){
		string s;cin>>s;
		bool flag2=true;
		int Z=0;
		for(int i=0;i<17;i++)
		{
			if(s[i]<'0'||s[i]>'9')
			{
				flag1=flag2=false;
				break;
			}
			Z+=weight[i]*(s[i]-'0');
		}
		if(flag2)
		{
			Z%=11;
			if(s[17]!=M[Z])
				flag1=flag2=false;
		}
		if(!flag2)
			cout<<s<<endl;
	}
	if(flag1)
	cout<<"All passed"<<endl;
	return 0;
}
