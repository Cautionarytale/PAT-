#include<iostream>
using namespace std;
#include<algorithm>
const int maxn=100010;
int pos[maxn];
int main()
{
	int n,ans=0;
	cin>>n;
	int left=n-1,num;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		pos[num]=i;
		if(num==i&&num!=0)
			left--;
	}
	int k=1;
	while(left>0){
		if(pos[0]==0)
		{
			while(k<n)
			{
				if(pos[k]!=k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0]!=0)
		{
			swap(pos[0],pos[pos[0]]);
			ans++;
			left--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

