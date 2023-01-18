#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char DAY[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	string s1,s2,s3,s4;cin>>s1>>s2>>s3>>s4;
	int min_l=min(s1.length(),s2.length());
	int idx,hh,mm;
	int i;
	for(i=0;i<min_l;i++)
	{
		if(s1[i]==s2[i])
		{
			if(s1[i]>='A'&&s1[i]<='G')
			{
				idx=s1[i]-'A';
				break;
			}
		}	
	}
	for(int j=i+1;j<min_l;j++)
	{
		if(s1[j]==s2[j])
		{
			if((s1[j]>='0'&&s1[j]<='9')||(s1[j]>='A'&&s1[j]<='N'))
			{
				if(s1[j]>='0'&&s1[j]<='9')
					hh=s1[j]-'0';
				else
					hh=s1[j]-'A'+10;
				break;	
			}
		}
		
	} 
	int m_l=min(s3.length(),s4.length());
	for(int k=0;k<m_l;k++)
	{
		if(s3[k]==s4[k])
		{
			if((s3[k]>='a'&&s3[k]<='z')||(s3[k]>='A'&&s3[k]<='Z'))
			{
				mm=k;
				break;
			}
		}	
	}
	cout<<DAY[idx]<<' ';
	printf("%02d:%02d",hh,mm);
	return 0;
}
