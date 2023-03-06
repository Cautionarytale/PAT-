#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<map>
map<string,int>mp;
bool check(char ch){
	if(ch>='0'&&ch<='9')return true;
	if(ch>='a'&&ch<='z')return true;
	if(ch>='A'&&ch<='Z')return true;
	return false;
}
int main()
{
	string str;getline(cin,str);
	int Max=0;string ret;
	int i=0;
	while(i<str.length()){
		string word;
		while(i<str.length()&&check(str[i]))
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i]+=32;
			word+=str[i];
			i++;
		}
		if(word!="")
		{
			if(mp.find(word)!=mp.end())mp[word]++;
			else mp[word]=1;
		}
		while(i<str.length()&&!check(str[i]))
			i++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>Max)
		{
			Max=it->second;
			ret=it->first;
		}
	}
	cout<<ret<<' '<<Max<<endl;
	return 0;
}
