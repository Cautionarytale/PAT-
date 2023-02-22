//²î·ÖÊý×é 
#include<iostream>
using namespace std;
#include<algorithm>
const int N=100010;
int sum[N];
int n,S,nearS=100000010;
int main()
{
	scanf("%d%d",&n,&S);
	sum[0];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int j=upper_bound(sum+i,sum+n+1,sum[i-1]+S)-sum;
		if(sum[j-1]-sum[i-1]==S){
			nearS=S;
			break;
		}
		else if(j<=n&&sum[j]-sum[i-1]<nearS){
			nearS=sum[j]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=upper_bound(sum+i,sum+n+1,sum[i-1]+nearS)-sum;
		if(sum[j-1]-sum[i-1]==nearS){
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
}

