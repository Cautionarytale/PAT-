#include <cstdio>
#include <algorithm>
#include <string.h>
int T(char a){                            //把字符转成数字的函数
            int n=0;
            if(a<='9'&&a>='0'){
                n=a-'0';
            }
            if(a>='a'&&a<='z'){
                n=a-'a'+10;
            }
            if(a>='A'&&a<='Z'){
                n=a-'A'+10;
            }
        return n;
}
 
int main(){
    char c1[90];
    char c2[90];
    int check[80]={0};        
    scanf("%s%s",c1,c2);
    int len1=strlen(c1);
    int len2=strlen(c2);
    for(int i=0;i<len1;i++){
        int j;
        for(j=0;j<len2;j++){
            if(c2[j]<='z'&&c2[j]>='a'){
                    c2[j]=c2[j]-32;
                }
            if(c1[i]<='z'&&c1[i]>='a'){
                    c1[i]=c1[i]-32;
                }
            if(c2[j]==c1[i]){
                break;
            }
        }
 
        if(j==len2&&check[T(c1[i])]==0){
            printf("%c",c1[i]);
            check[T(c1[i])]=1;
        }
    }
 
return 0;
}
