#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
map<string,set<int>>mpTitle,mpAuthor,mpKeyword,mpPub,mpYear;
void query(map<string,set<int>>&mp,string&s){
	if(mp.find(s)==mp.end())cout<<"Not Found"<<endl;
	else{
		for(auto it=mp[s].begin();it!=mp[s].end();it++)
		{
			printf("%07d\n",*it);
		}
	}
}
int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		int id;scanf("%d",&id);getchar();
		string title;getline(cin,title);mpTitle[title].insert(id);
		string author;getline(cin,author);mpAuthor[author].insert(id);
		string keyword;
		while(cin>>keyword)
		{
			mpKeyword[keyword].insert(id);
			char ch=getchar();
			if(ch=='\n')break;
		} 
		string pub;getline(cin,pub);mpPub[pub].insert(id);
		string year;getline(cin,year);mpYear[year].insert(id);
	}
	int q;cin>>q;
	for(int i=0;i<q;i++)
	{
		int type;
		scanf("%d: ",&type);
		string s;getline(cin,s);
		cout<<type<<": "<<s<<endl;
		if(type==1)query(mpTitle,s);
		else if(type==2)query(mpAuthor,s);
		else if(type==3)query(mpKeyword,s);
		else if(type==4)query(mpPub,s);
		else query(mpYear,s);
	}
	return 0;
}
