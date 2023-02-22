#include<iostream>
using namespace std;
#include<algorithm>
const int maxn=100010;
int a[maxn];
int main()
{
	int n,p;cin>>n>>p;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=1;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		int j=upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
}
