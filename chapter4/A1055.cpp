//根据M<=100来进行预处理（将每个年龄的财富值100名之后的人剔除掉），否则会超时 
#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
const int maxn=100010;
struct Person{
	char name[10];
	int age,worth;
}p[maxn],valid[maxn];
int Age[maxn]={0};
bool cmp(Person a,Person b){
	if(a.worth!=b.worth)return a.worth>b.worth;
	else if(a.age!=b.age)return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
int main()
{
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>p[i].name>>p[i].age>>p[i].worth;
	sort(p,p+n,cmp);
	int vnum=0;
	for(int i=0;i<n;i++)
	{
		if(Age[p[i].age]<100){
			Age[p[i].age]++;
			valid[vnum++]=p[i];
		}
	}
	int m,ageL,ageR;
	for(int i=1;i<=k;i++)
	{
		cin>>m>>ageL>>ageR;
		cout<<"Case #"<<i<<":"<<endl;
		int printNum=0;
		for(int j=0;j<vnum&&printNum<m;j++)
		{
			if(valid[j].age>=ageL&&valid[j].age<=ageR){
				cout<<valid[j].name<<' '<<valid[j].age<<' '<<valid[j].worth<<endl;
				printNum++;
			}
		}
		if(printNum==0)
			cout<<"None"<<endl;
	}
	return 0;
}
