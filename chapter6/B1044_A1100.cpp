#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<map>
string unit1[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string unit2[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

string num2str[170];
map<string,int>str2num;
void init(){//´ò±í 
	for(int i=0;i<13;i++)
	{
		num2str[i]=unit1[i];
		str2num[unit1[i]]=i;
		num2str[i*13]=unit2[i];
		str2num[unit2[i]]=i*13;
	}
	for(int i=1;i<13;i++)
	{
		for(int j=1;j<13;j++)
		{
			num2str[i*13+j]=unit2[i]+" "+unit1[j];
			str2num[unit2[i]+" "+unit1[j]]=i*13+j;
		}
	}
}
int main()
{
	init();
	int n;cin>>n;getchar();
	for(int i=0;i<n;i++)
	{
		string s;getline(cin,s);
		if(s[0]>='0'&&s[0]<='9')
		{
			int ret=0;
			while(s.length()>0){
				ret=ret*10+(s[0]-'0');
				s.erase(s.begin());
			}
			cout<<num2str[ret]<<endl;
		}
		else cout<<str2num[s]<<endl;
	}
	return 0;
}
