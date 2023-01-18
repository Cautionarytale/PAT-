#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<cstring>
const int maxn=110;
char A[maxn],B[maxn],C[maxn];
int main()
{
	scanf("%s %s",A,B);
	int len_A=strlen(A);
	int len_B=strlen(B);
	int max_len=max(len_A,len_B);
	reverse(A,A+len_A);
	reverse(B,B+len_B);
	for(int i=0;i<max_len;i++)
	{
		int num_A=i>=len_A?0:A[i]-'0';
		int num_B=i>=len_B?0:B[i]-'0';
		if(i%2==0){
			int temp=(num_A+num_B)%13;
			if(temp==10){
				C[i]='J';
			}
			else if(temp==11){
				C[i]='Q';
			}
			else if(temp==12){
				C[i]='K'; 
			}
			else
			{
				C[i]=temp+'0';
			}
		}
		else{
			int temp=num_B-num_A;
			if(temp<0)temp+=10;
			C[i]=temp+'0';
		}
	} 
	reverse(C,C+max_len);
	puts(C);
	return 0;
}
