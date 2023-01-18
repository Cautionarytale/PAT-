#include<iostream>
using namespace std;
#include<stack>
char number[11][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	string s;cin>>s;
	int ans=0;
	for(auto&e:s){
		ans+=e-'0';
	}
	if(!ans){
		cout<<"zero";
		return 0;
	}
	stack<string>stk;
	while(ans){
		stk.push(number[ans%10]);
		ans/=10;
	}
	cout<<stk.top();stk.pop();
	while(!stk.empty()){
		cout<<' '<<stk.top();
		stk.pop();
	}
	return 0;
}
