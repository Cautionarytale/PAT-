#include<iostream>
using namespace std;
struct person
{
	string number;
	int pos1;
	int pos2;	
}p[1010];
int main()
{
	int N;cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>p[i].number>>p[i].pos1>>p[i].pos2;
	}
	int M;cin>>M;
	for(int i=0;i<M;i++)
	{
		int pos1;cin>>pos1;
		for(int i=0;i<N;i++)
		{
			if(p[i].pos1==pos1)
			{
				cout<<p[i].number;
				cout<<' ';
				cout<<p[i].pos2<<endl;
			}
		}
	}
	
	
	return 0;
}


