#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdio>
const int MAXN=100010;
const int INF=0x3fffffff;
int a[MAXN],lmax[MAXN],rmin[MAXN];
int ans[MAXN],num=0;
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	lmax[0]=0;
	for(int i=1;i<n;i++)
		lmax[i]=max(lmax[i-1],a[i-1]);
	rmin[n-1]=INF;
	for(int i=n-2;i>=0;i--)
		rmin[i]=min(rmin[i+1],a[i+1]);
	for(int i=0;i<n;i++){
		if(lmax[i]<a[i]&&rmin[i]>a[i])
			ans[num++]=a[i];
	}
	cout<<num<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<ans[i];
		if(i<num-1)cout<<' ';
	}
	cout<<endl;
	return 0;
}

