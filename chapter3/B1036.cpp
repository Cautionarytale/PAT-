#include<iostream>
using namespace std;
int main()
{
	int row,col;
	int n;cin>>n;
	char ch;cin>>ch;
	col =n;
	row=col%2?col/2+1:col/2;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i==0||i==row-1||j==0||j==col-1)
				cout<<ch;
			else 
				cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
