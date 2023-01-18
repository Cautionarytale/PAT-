#include<iostream>
using namespace std;
#include<algorithm>
struct Student{
	string name;
	string id;
	int score;
};
int main()
{
	int max_score=-1,min_score=101;
	int max_index,min_index;
	int n;cin>>n;
	Student*s=new Student[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i].name>>s[i].id>>s[i].score;
		if(max_score<s[i].score)
		{
			max_score=s[i].score;
			max_index=i;
		}
		if(min_score>s[i].score)
		{
			min_score=s[i].score;
			min_index=i;
		}
	}
	cout<<s[max_index].name<<' '<<s[max_index].id<<endl;
	cout<<s[min_index].name<<' '<<s[min_index].id<<endl;
	return 0;
}
