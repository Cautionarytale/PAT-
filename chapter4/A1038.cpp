#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
const int maxn=10010;
string str[maxn];
bool cmp(string a,string b){
	return a+b<b+a;
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>str[i];
	sort(str,str+n,cmp);
	string ans;
	for(int i=0;i<n;i++)
	{
		ans+=str[i];
	}
	while(!ans.empty()&&ans[0]=='0')
		ans.erase(ans.begin());
	if(ans.size()==0)cout<<0;
	else cout<<ans;
	return 0;
}

