#include<iostream>
using namespace std;
#include<stack>
int main()
{
	stack<string>stk;
	string s;
	while(cin>>s){
		stk.push(s);
	}
	cout<<stk.top();stk.pop();
	while(!stk.empty())
	{
		cout<<' '<<stk.top();
		stk.pop();
	}
	return 0;
}
