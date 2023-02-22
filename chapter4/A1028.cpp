#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
struct Student{
	char id[10];
	char name[10];
	int score;
}s[100010];
bool cmp1(Student a,Student b){
	return strcmp(a.id,b.id)<0;
}
bool cmp2(Student a,Student b){
	if(strcmp(a.name,b.name)!=0)return strcmp(a.name,b.name)<0;
	else return strcmp(a.id,b.id)<0;
}
bool cmp3(Student a,Student b){
	if(a.score!=b.score)return a.score<b.score;
	else return strcmp(a.id,b.id)<0;
}
int main()
{
	int n,C;cin>>n>>C;
	for(int i=0;i<n;i++)
		cin>>s[i].id>>s[i].name>>s[i].score;
	if(C==1)sort(s,s+n,cmp1);
	else if(C==2)sort(s,s+n,cmp2);
	else sort(s,s+n,cmp3);  
	for(int i=0;i<n;i++)
		cout<<s[i].id<<' '<<s[i].name<<' '<<s[i].score<<endl;
	return 0;
}
