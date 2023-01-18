#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Student{
	string name;
	char gender;
	string id;
	int score;
}temp;
bool cmp(Student s1,Student s2)
{
	return s1.score<s2.score;
}
int main()
{
	vector<Student>boys,girls;
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp.name>>temp.gender>>temp.id>>temp.score;
		if(temp.gender=='M')boys.push_back(temp);
		else girls.push_back(temp);
	}
	sort(boys.begin(),boys.end(),cmp);
	sort(girls.begin(),girls.end(),cmp);
	int s1=boys.size(),s2=girls.size();
	if(girls.empty())cout<<"Absent"<<endl;
	else cout<<girls[s2-1].name<<' '<<girls[s2-1].id<<endl;
	
	if(boys.empty())cout<<"Absent"<<endl;
	else cout<<boys[0].name<<' '<<boys[0].id<<endl;
	
	if(boys.empty()||girls.empty())cout<<"NA"<<endl;
	else cout<<girls[s2-1].score-boys[0].score<<endl;
	return 0;
}
