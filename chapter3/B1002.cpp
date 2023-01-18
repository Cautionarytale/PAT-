#include<iostream>
using namespace std;
#include<stack>
char str[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
	string s;cin>>s;
	long long ret=0;
	for(int i=0;i<s.length();i++)
		ret+=s[i]-'0';
	stack<string>stk;
	while(ret)
	{
		int val=ret%10;
		stk.push(str[val]);
		ret/=10;
	}
	cout<<stk.top();
	stk.pop();
	while(!stk.empty())
	{
		cout<<' '<<stk.top();
		stk.pop();
	}
	return 0;
}

