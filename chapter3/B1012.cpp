#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<cstdio>
#include<algorithm>
int A(int val)
{
	if(val%5==0&&val&1==1)
		return 5;
	return val%5;
}
int main()
{
	int N;cin>>N;
	vector<vector<int>>v(6);
	for(int i=0;i<N;i++)
	{
		int val;cin>>val;
		v[A(val)].push_back(val);
	}
	
	if(v[0].empty())
		cout<<"N";
	else
	{
		int A1=accumulate(v[0].begin(),v[0].end(),0);
		cout<<A1;
	}
	if(v[1].empty())
		cout<<' '<<"N";
	else
	{
		int A2=0;
		int coef=1;
		for(auto&e:v[1])
		{
			A2+=coef*e;coef*=-1;
		}
		cout<<' '<<A2;
	}
	if(v[2].empty())
		cout<<' '<<"N";
	else
	{
		int A3=v[2].size();
		cout<<' '<<A3;
	}		
	if(v[3].empty())
		cout<<' '<<"N";
	else
	{
		float s=v[3].size();
		float A4=accumulate(v[3].begin(),v[3].end(),0)/s;
		printf(" %.1f",A4);
	}
	if(v[4].empty())
		cout<<' '<<"N";
	else
	{
		int A5=*max_element(v[4].begin(),v[4].end());
		cout<<' '<<A5;
	}
	
	
	
	return 0;
}
