#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdio>
struct Student{
	int GE,GI,sum;
	int r,stuID;
	int cho[6];//K个志愿 
}stu[40010];
struct School{
	int quota;
	int stuNum;
	int id[40010];
	int lastAdmit;//最后一名录取学生的id 
}sch[110];
bool cmp_stu(Student a,Student b){
	if(a.sum!=b.sum)return a.sum>b.sum;
	else return a.GE>b.GE;
}
bool cmp_id(int a,int b){
	return stu[a].stuID<stu[b].stuID;
}
int main()
{
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>sch[i].quota;
		sch[i].stuNum=0;
		sch[i].lastAdmit=-1;
	}
	for(int i=0;i<n;i++)
	{
		stu[i].stuID=i;
		cin>>stu[i].GE>>stu[i].GI;
		stu[i].sum=stu[i].GE+stu[i].GI;
		for(int j=0;j<k;j++){
			cin>>stu[i].cho[j];
		}
	}
	sort(stu,stu+n,cmp_stu);
	for(int i=0;i<n;i++)
	{
		if(i>0&&stu[i].sum==stu[i-1].sum&&stu[i].GE==stu[i-1].GE)
			stu[i].r=stu[i-1].r;
		else stu[i].r=i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int choice=stu[i].cho[j];
			int num=sch[choice].stuNum;
			int last=sch[choice].lastAdmit;
			if(num<sch[choice].quota||(last!=-1&&stu[i].r==stu[last].r))
			{
				sch[choice].id[num]=i;
				sch[choice].lastAdmit=i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(sch[i].stuNum>0)
		{
			sort(sch[i].id,sch[i].id+sch[i].stuNum,cmp_id);
			for(int j=0;j<sch[i].stuNum;j++)
			{
				cout<<stu[sch[i].id[j]].stuID;
				if(j<sch[i].stuNum-1)
					cout<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}
