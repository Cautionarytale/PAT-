#include<iostream>
using namespace std;
#include<cstdio>
const int Sickle=29;
const int Glleon=17*29;
int main()
{
	int a1,b1,c1;
	int a2,b2,c2;
	scanf("%d.%d.%d",&a1,&b1,&c1);
	scanf("%d.%d.%d",&a2,&b2,&c2);
	int price1=a1*Glleon+b1*Sickle+c1;
	int price2=a2*Glleon+b2*Sickle+c2;
	int change=price2-price1;
	if(change<0){
		cout<<'-';
		change=-change;
	}
	cout<<change/Glleon<<'.'<<change%Glleon/Sickle<<'.'<<change%Sickle<<endl;
	return 0;
}
