#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;cin>>n;
	vector<char>v;
	int b=n/100;n%=100;
	while(b--)
		v.push_back('B');
	int s=n/10;n%=10;
	while(s--)
		v.push_back('S');
	for(int i=1;i<=n;i++)
		v.push_back(i+'0');
	for(auto&e:v)
		cout<<e;
	return 0;
}
