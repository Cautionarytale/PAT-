#include<iostream>
using namespace std;
#include<queue>
const int maxn=1010;
struct Mouse{
	int weight;
	int r;
}m[maxn];
queue<int>q;
int main(){
	int np,ng;cin>>np>>ng;
	int temp=np;//tempΪ��ǰ������
	int group;
	for(int i=0;i<np;i++)
	{
		cin>>m[i].weight;
	} 
	for(int i=0;i<np;i++)
	{
		int val;cin>>val;
		q.push(val);
	}
	while(q.size()!=1)
	{
		if(temp%ng==0)group=temp/ng;
		else group=temp/ng+1;
		for(int i=0;i<group;i++)
		{
			int k=q.front();//kΪ�����ı��
			for(int j=0;j<ng;j++)
			{
				if(i*ng+j>=temp)break;
				int top=q.front();
				if(m[top].weight>m[k].weight)
					k=top;
				m[top].r=group+1;
				q.pop();
			}
			q.push(k);	
		}
		temp=group;
	}
	m[q.front()].r=1;
	for(int i=0;i<np;i++)
	{
		cout<<m[i].r;
		if(i!=np-1)cout<<' ';
	}
	
	
	return 0;
}
