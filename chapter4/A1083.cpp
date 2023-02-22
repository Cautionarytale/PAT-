#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
struct Student{
	string name;
	string id;
	int score;
};
bool cmp(Student a,Student b){
	return a.score>b.score;
}
int main()
{
	int n;cin>>n;
	vector<Student>s(n); 
	for(int i=0;i<n;i++)
	{
		cin>>s[i].name>>s[i].id>>s[i].score;
	}
	sort(s.begin(),s.end(),cmp);
	int L,R;cin>>L>>R;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(s[i].score>=L&&s[i].score<=R)
		{
			flag=true;
			cout<<s[i].name<<' '<<s[i].id<<endl;
		}
	}
	if(!flag)
		cout<<"NONE"<<endl;
	return 0;
} 
