#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
int main()
{
	stack<char>stk;
	int n;cin>>n;getchar();//»»ÐÐ 
	vector<string>v;
	int min_len=0x3f3f3f3f;
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		reverse(s.begin(),s.end());
		int l=s.length();
		min_len=min(min_len,l);
		v.push_back(s);
	}
	for(int i=0;i<min_len;i++)
	{
		char ch=v[0][i];bool flag=true;
		for(int j=0;j<n;j++)
		{
			if(v[j][i]!=ch){
				flag=false;
				break;
			}
		}
		if(flag)
		{
			stk.push(ch);
		}
		else break;
	}
	if(stk.empty())cout<<"nai";
	else
	{
		while(!stk.empty()){
			printf("%c",stk.top());
			stk.pop();
		}
	}
	return 0;
}
