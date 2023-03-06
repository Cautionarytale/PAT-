#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
int n;
string deal(string s,int&e){
	int idx=0;
	while(s.length()>0&&s[0]=='0')
	{
		s.erase(s.begin());
	}
		if(s[0]=='.'){//a-type
			s.erase(s.begin());
			while(s.length()>0&&s[0]=='0')
			{
				s.erase(s.begin());
				e--;
			}
		}
		else{//b-type
			while(idx<s.length()&&s[idx]!='.')
			{
				idx++;e++;
			}
			if(idx<s.length())s.erase(s.begin()+idx);
		}
		if(s.length()==0)e=0;
		idx=0;
		int num=0;
		string ret;
		while(num<n){
			if(idx<s.length())ret+=s[idx++];
			else ret+='0';
			num++;
		}
		return ret;
}
int main()
{
	string str1,str2;
	cin>>n>>str1>>str2;
	int e1=0;
	int e2=0;
	string s1=deal(str1,e1);
	string s2=deal(str2,e2);
	if(s1==s2&&e1==e2)
	{
		cout<<"YES 0."<<s1<<"*10^"<<e1<<endl;
	}
	else
	{
		cout<<"NO"<<" 0."<<s1<<"*10^"<<e1<<" 0."<<s2<<"*10^"<<e2<<endl;
	}
	return 0;
}
