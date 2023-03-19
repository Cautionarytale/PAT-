#include<iostream>
using namespace std;
#include<stack>
const int maxn=1010;
int a[maxn];
int main(){
	int m,n,k;cin>>m>>n>>k;
	while(k--){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cur=1;
		bool flag=true;
		stack<int>stk;
		for(int i=1;i<=n;i++)
		{
			stk.push(i);
			if(stk.size()>m)
			{
				flag=false;
				break;
			}
			while(!stk.empty()&&stk.top()==a[cur])
			{
				cur++;
				stk.pop();
			}
		}
		if(stk.empty()&&flag){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
