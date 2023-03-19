#include<iostream>
using namespace std;
#include<algorithm>
const int maxn=1010;
int CBT[maxn],origin[maxn];
int n,idx=0;
void inorder(int root){
	if(root>n)return;
	inorder(root*2);
	CBT[root]=origin[idx++];
	inorder(root*2+1);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>origin[i];
	}
	sort(origin,origin+n);
	inorder(1);
	for(int i=1;i<=n;i++){
		cout<<CBT[i];
		if(i!=n)cout<<' ';
	}
	return 0;
}
