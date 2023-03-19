#include<iostream>
using namespace std;
#include<vector>
#include<cstdio> 
int n,k,p;
vector<int>ans,fac,temp;
int facSumMax=-1;
int power(int x)//��x^p 
{
	int ans=1;
	for(int i=0;i<p;i++)
	{
		ans*=x;
	} 
	return ans;
}
void init()
{
	for(int i=0;i<=n;i++)
	{
		int temp=power(i);
		fac.push_back(temp);
	}
//	int i=0,temp=0;
//	while(temp<=n){
//		fac.push_back(temp);
//		temp=power(++i);
//	}
}
void DFS(int index,int nowK,int sum,int facSum){//index�ǵ�ǰѡȡ������fac�е��±꣬nowK�ǵ�ǰѡȡ�����ָ�����sum�ǵ�ǰ����ʽ�ĺͣ�facSum�ǵ���֮�� 
	if(nowK==k&&sum==n)
	{
		if(facSum>facSumMax)
		{
			ans=temp;
			facSumMax=facSum;
		}
		return;
	}
	if(sum>n||nowK>k)return;//ʧ��
	if(index>=1)
	{
		temp.push_back(index);
		DFS(index,nowK+1,sum+fac[index],facSum+index);
		temp.pop_back();
		DFS(index-1,nowK,sum,facSum);
	} 
}
int main()
{
	//cin>>n>>k>>p;
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(facSumMax==-1)printf("Impossible\n");
	else
	{
//		cout<<n<<" = ";
//		cout<<ans[0]<<"^"<<p;
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++)
		{
			//cout<<" + "<<ans[i]<<"^"<<p;
			printf(" + %d^%d",ans[i],p);
		}
	}
	return 0;
}
