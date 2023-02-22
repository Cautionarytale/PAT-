#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn=10010;
struct Student{
	int id;
	int score[6];//��Ŀ�÷� 
	bool flag;//��¼�Ƿ�����ͨ��������ύ
	int score_all;//�ܷ�
	int solve; 
}s[maxn];
int n,k,m;//����Ϊ������������Ŀ�������ύ���� 
int full[6];//ÿ���������
bool cmp(Student a,Student b){
	if(a.score_all!=b.score_all)return a.score_all>b.score_all;
	else if(a.solve!=b.solve)return a.solve>b.solve;
	else return a.id<b.id;
} 
void init(){//��ʼ�� 
	for(int i=1;i<=n;i++){
		s[i].id=i;
		s[i].score_all=0;
		s[i].solve=0;
		s[i].flag=false;
		memset(s[i].score,-1,sizeof(s[i].score));//��Ŀ�÷ּ�Ϊ-1 
	}
}
int main()
{
	cin>>n>>k>>m;
	init();
	for(int i=1;i<=k;i++)
		cin>>full[i];
	int u_id,p_id,score_obtained;
	for(int i=0;i<m;i++)
	{
		cin>>u_id>>p_id>>score_obtained;
		if(score_obtained!=-1)
			s[u_id].flag=true;
		if(score_obtained==-1&&s[u_id].score[p_id]==-1){
			//"��һ��"������󣬼�Ϊ0��
			s[u_id].score[p_id]=0; 
		}
		if(score_obtained==full[p_id]&&s[u_id].score[p_id]<full[p_id])
			s[u_id].solve++;
		if(score_obtained>s[u_id].score[p_id])
			s[u_id].score[p_id]=score_obtained;
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=k;j++)
	 	{
	 		if(s[i].score[j]!=-1)
	 			s[i].score_all+=s[i].score[j];
		 }
	 }
	 sort(s+1,s+n+1,cmp);
	 int r=1;
	 for(int i=1;i<=n&&s[i].flag==true;i++)
	 {
	 	if(i>1&&s[i].score_all!=s[i-1].score_all){
	 		r=i;
		}
		printf("%d %05d %d",r,s[i].id,s[i].score_all);
		for(int j=1;j<=k;j++)
		{
			if(s[i].score[j]==-1)
				cout<<" -";
			else cout<<' '<<s[i].score[j];
		 } 
		 cout<<endl;
	 }
	return 0;
}
