#include<iostream>
using namespace std;
#include<algorithm>
const int maxn=2000010;
int a[maxn];
int main()
{
	int n,m;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=n;i<n+m;i++)
		cin>>a[i];
	sort(a,a+m+n);
	cout<<a[(m+n-1)/2];
	return 0;
}

