#include<iostream>

#include<cstdio>
#include<cstring>
int main()
{
	char str[10010];scanf("%s",str);
	int pos=0;//pos是'E'所在的位置 
	while(str[pos]!='E')
		pos++;
	if(str[0]=='-')printf("-");
	int exp=0;//指数绝对值 
	int len=strlen(str);
	for(int i=pos+2;i<len;i++)
		exp=exp*10+(str[i]-'0');
	if(!exp){
		for(int i=1;i<pos;i++)
			printf("%c",str[i]);
	}
	else
	{
		if(str[pos+1]=='-')
		{
			printf("0.");
			for(int i=0;i<exp-1;i++)//输出exp-1个0 
				printf("0");
			for(int i=1;i<pos;i++)
			{
				if(str[i]=='.')
					continue;
				printf("%c",str[i]);
			}	
		}
		else
		{
			for(int i=1;i<pos;i++)
			{
				if(str[i]=='.')
					continue;
				printf("%c",str[i]);
				if(i==exp+2&&i!=pos-1)
					printf(".");
			}
			for(int i=0;i<exp-(pos-3);i++)
				printf("0");
		}
	}
	return 0;
}


