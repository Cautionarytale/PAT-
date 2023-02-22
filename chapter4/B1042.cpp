#include<iostream>
using namespace std;
int Hash[30]={0};
int main()
{
	string s;getline(cin,s);
	for(auto&e:s)
	{
		if(e>='a'&&e<='z')
			Hash[e-'a']++;
		else if(e>='A'&&e<='Z')
			Hash[e-'A']++;
	}
	char ch='a';int k=0;
	for(int i=1;i<26;i++)
	{
		if(Hash[i]>Hash[k])
		{
			k=i;
			ch='a'+i;
		}
	}
	cout<<ch<<' '<<Hash[k];
	return 0;
}
