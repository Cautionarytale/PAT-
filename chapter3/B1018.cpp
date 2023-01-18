#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int transform(char ch)
{
	if(ch=='B')
		return 0;
	else if(ch=='C')
		return 1;
	else if(ch=='J')
		return 2;
}
char mp[3]={'B','C','J'};
int main()
{
	vector<int>v1(3,0),v2(3,0);
	int N;cin>>N;
	char c1,c2;
	int win1=0,win2=0;
	int deuce1=0,deuce2=0;
	int lose1=0,lose2=0;
	while(N--)
	{
		cin>>c1>>c2;
		int num1=transform(c1);
		int num2=transform(c2);
		if(num1==num2)
		{
			deuce1++;
			deuce2++;
		}
		else
		{
			if((num1+1)%3==num2)
			{
				v1[num1]++;
				win1++;
				lose2++;
			}
			else
			{
				v2[num2]++;
				lose1++;
				win2++;
			}
		}		
	}
	cout<<win1<<' '<<deuce1<<' '<<lose1<<endl;
	cout<<win2<<' '<<deuce2<<' '<<lose2<<endl;
	int index1=max_element(v1.begin(),v1.end())-v1.begin();
	int index2=max_element(v2.begin(),v2.end())-v2.begin();
	cout<<mp[index1]<<' '<<mp[index2]<<endl;
	return 0;
}
