#include<iostream>
using namespace std;
#include<map>
int main()
{
	string str;getline(cin,str);
	string s;getline(cin,s);
	map<char,int>mp;
	for(auto&e:s)
		mp[e]++;
	for(auto&e:str)
	{
		if(!mp.count(e))
		cout<<e;
	}
	return 0;
}
