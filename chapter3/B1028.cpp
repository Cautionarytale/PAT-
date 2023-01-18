#include<iostream>
using namespace std;
#include<cstdio>
struct Person{
	char name[15];
	int year;
	int month;
	int  day;
}Left,Right,youngest,oldest,temp;
bool youngerthan(Person p1,Person p2){
	if(p1.year!=p2.year)return p1.year>=p2.year;
	else
	{
		if(p1.month!=p2.month)return p1.month>=p2.month;
		return p1.day>=p2.day;
	}
}
void init()
{
	Left.year=1814;Left.month=9;Left.day=6;
	Right.year=2014;Right.month=9;Right.day=6;
	youngest.year=1814;youngest.month=9;youngest.day=6;
	oldest.year=2014;oldest.month=9;oldest.day=6;
}
int main()
{
	init();
	int cnt=0;
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d/%d/%d",temp.name,&temp.year,&temp.month,&temp.day);
		if(youngerthan(temp,Left)&&youngerthan(Right,temp))
		{
			if(youngerthan(temp,youngest))
				youngest=temp;
			if(youngerthan(oldest,temp))
				oldest=temp;
			cnt++;
		}
	}
	if(!cnt)cout<<"0";
	else
		printf("%d %s %s\n",cnt,oldest.name,youngest.name);
	return 0;
}
