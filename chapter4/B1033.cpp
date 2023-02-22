#include<iostream>
using namespace std;
#include<cstring>
char Hash[256];
int main()
{
	memset(Hash,true,sizeof(Hash));
	string wrong;getline(cin,wrong);
	for(auto e:wrong)
	{
		if(e>='A'&&e<='Z')
			e+=32;
		Hash[e]=false;
	}
	string str;getline(cin,str);
	for(auto&e:str)
	{
		if(e>='A'&&e<='Z')
		{
			int low=e+32;
			if(Hash[low]&&Hash['+'])
				cout<<e;
		}
		else if(Hash[e])
			cout<<e;
	}
	cout<<endl;
	return 0;
}
