#include<iostream>
using namespace std;
struct admin{
	string name;
	string password;
}a[1010];
bool modify(string&password){
	bool flag=false;
	for(int i=0;i<password.length();i++){
		if(password[i]=='1'){
			flag=true;
			password[i]='@';
		}
		else if(password[i]=='0'){
			flag=true;
			password[i]='%';
		}
		else if(password[i]=='l'){
			flag=true;
			password[i]='L';
		}
		else if(password[i]=='O'){
			flag=true;
			password[i]='o';
		}
	}
	return flag;
}
int main()
{
	int n;cin>>n;
	//bool flag1=false;
	int cnt=0;
	for(int i=0;i<n;i++){
		string name,password;cin>>name>>password;
		if(modify(password))
		{
		//	flag1=true;
			a[cnt].name=name;
			a[cnt++].password=password;
		}
	}
	if(cnt){
		cout<<cnt<<endl;
		for(int i=0;i<cnt;i++){
			cout<<a[i].name<<' '<<a[i].password<<endl;
		}
	}
	else{
		if(n==1){
			cout<<"There is "<<n<<' '<<"account and no account is modified"<<endl;
		}
		else{
			cout<<"There are "<<n<<' '<<"accounts and no account is modified"<<endl;
		}
	}
	return 0;
}
