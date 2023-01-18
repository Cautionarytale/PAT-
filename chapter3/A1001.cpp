#include<iostream>
using namespace std;
#include<algorithm>
#include<stack>
#include<cstdlib>
stack<int>stk;
int main()
{
	int a,b,ans=0;
	scanf("%d %d",&a,&b);
	a=a+b;
	b=abs(a);
	if(a<0){
		printf("-");
	}
	else if(a==0){
		cout<<'0';
		return 0;
	}
	while(b!=0){
		stk.push(b%10);
		b/=10;
	}
	int cnt=1;
	b=stk.size();
	while(!stk.empty()){
		printf("%d",stk.top());
		stk.pop();
		if(--b%3==0&&!stk.empty())
			printf(",");
		cnt++;
	}
	return 0;
}
