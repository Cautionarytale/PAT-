#include<iostream>
using  namespace std;
#include<algorithm>
#include<numeric>
#include<cstdio>
const int maxn=1010;
int fa[maxn];
int root[maxn]={0};
int activity[maxn]={0};
int n;
int Find(int x)
{
    return x==fa[x]?x:(fa[x]=Find(fa[x]));
}
void Union(int a,int b){
    int fA=Find(a),fB=Find(b);
    if(fA!=fB)fa[fA]=fB;
}
int main()
{
    cin>>n;int k;
    iota(fa,fa+n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%d:",&k);
        for(int j=0;j<k;j++)
        {
            int val;cin>>val;
            if(activity[val]==0)
                activity[val]=i;
            Union(i,Find(activity[val]));
        }
    }
    for(int i=1;i<=n;i++){
        root[Find(i)]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(root[i]!=0)ans++;
    sort(root+1,root+n+1,greater<int>());
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
    {
        cout<<root[i];
        if(i!=ans)cout<<' ';
    }
    return 0;
}
