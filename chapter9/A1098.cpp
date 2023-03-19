#include<iostream>
using namespace std;
const int maxn=111;
int origin[maxn],tempOri[maxn],changed[maxn];
int n;
bool isSame(int A[],int B[]){
	for(int i=1;i<=n;i++)
		if(A[i]!=B[i])return false;
	return true;
}
void showArray(int A[])
{
	for(int i=1;i<=n;i++)
	{
		cout<<A[i];
		if(i<n)cout<<' ';
	}
	cout<<endl;
}
bool insertSort(){
	bool flag=false;
	for(int i=2;i<=n;i++)
	{
		if(i!=2&&isSame(tempOri,changed))
			flag=true;
		int temp=tempOri[i];
		int j=i-1;
		while(temp<tempOri[j])
		{
			tempOri[j+1]=tempOri[j];
			j--;
		}
		tempOri[j+1]=temp;
		if(flag)return true;
	}
	return false;
}
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&tempOri[j+1]>tempOri[j])
			j=j+1;//ѡȡ���Һ����нϴ��һ�� 
		if(tempOri[j]>tempOri[i]){
			swap(tempOri[j],tempOri[i]);
			i=j;j=i*2;
		}else break;
	}
}
void heapSort(){
	bool flag=false;
	for(int i=n/2;i>=1;i--)//ǰn/2�����Ϊ��Ҷ�ڵ� 
	{
		downAdjust(i,n);//���� 
	}
	for(int i=n;i>1;i--){
		if(i!=n&&isSame(tempOri,changed)){
			flag=true;
		}
		swap(tempOri[i],tempOri[1]);
		downAdjust(1,i-1);
		if(flag==true)
			{
				showArray(tempOri);
				return;
			}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>origin[i];
		tempOri[i]=origin[i];
	}
	for(int i=1;i<=n;i++){
		cin>>changed[i];
	}
	if(insertSort()){
		cout<<"Insertion Sort"<<endl;
		showArray(tempOri);
	}else{
		cout<<"Heap Sort"<<endl;
		for(int i=1;i<=n;i++){
			tempOri[i]=origin[i];
		}
		heapSort();
	}
	return 0;
}
